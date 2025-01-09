#include "serviceRegistrationCente.h"

rpc::ServiceRegistrationCente::ServiceRegistrationCente(const muduo::net::InetAddress &address) : _server(&_loop, address, "ServiceRegistrationCente")
{
    _server.setMessageCallback(std::bind(MessageCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    _server.setConnectionCallback(std::bind(ConnectionCallback, this, std::placeholders::_1));
}

void rpc::ServiceRegistrationCente::start()
{
    _server.start();
    _loop.loop();
}

void rpc::ServiceRegistrationCente::MessageCallback(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp timestamp)
{
    RegistrationRequest request;
    if(!parseRequest(conn, buffer, request))
    {
        return;
    }
    if (!handleRequest(conn, request))
    {
        return;
    }
}
void rpc::ServiceRegistrationCente::ConnectionCallback(const muduo::net::TcpConnectionPtr &conn)
{
    if(conn->disconnected())
    {
        RegistrationRequest request;
        try
        {
           request=boost::any_cast<RegistrationRequest>(conn->getContext());
        }
        catch(const std::exception& e)
        {
            exit(1);
        }
        
        Ip ip=request.nginxip();
        if(--_refCount[ip] == 0)
        {
            for (int i = 0; i < request.providedservice().size(); i++)
            {
                _providedServices[request.providedservice()[i]].erase(ip);
                for (auto it = _requestedServices[request.providedservice()[i]].begin(); it != _requestedServices[request.providedservice()[i]].end(); it++)
                {
                    updateNodeService(*it, ip, request.providedservice()[i], false);
                }
            }
            _refCount.erase(ip);
        }
    }
}
/*
解析错误关闭连接(数据不足保留数据会关闭连接)
*/
bool rpc::ServiceRegistrationCente::parseRequest(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, RegistrationRequest &request)
{
    int headerSize = 0;
    MessageHeader header;

    if (buffer->readableBytes() < 4)
    {
        return false;
    }
    if ((headerSize = stringToUint(std::string(buffer->peek(), buffer->peek() + 4))) <= 0)
    {
        conn->shutdown();
        return false;
    }
    if (!header.ParseFromArray(buffer->peek() + 4, headerSize) || header.request_size() <= 0 || header.arg_size() != 0)
    {
        conn->shutdown();
        return false;
    }

    if (buffer->readableBytes() < headerSize + header.request_size())
    {
        return false;
    }
    if (!request.ParseFromArray(buffer->peek() + 4 + headerSize, header.request_size()))
    {
        conn->shutdown();
        return false;
    }

    buffer->retrieve(4 + headerSize + header.request_size() + header.arg_size());
    return true;
}

bool rpc::ServiceRegistrationCente::handleRequest(const muduo::net::TcpConnectionPtr &conn, const RegistrationRequest &request)
{
    if(respondToRequest(conn, request))
    {
        updateService(conn, request);
        return true;
    }
    else
    {
        return false;
    }
}

bool rpc::ServiceRegistrationCente::respondToRequest(const muduo::net::TcpConnectionPtr &conn, const RegistrationRequest &request)
{
    const google::protobuf::RepeatedPtrField<std::string> requestedservice = request.requestedservice();
    RegistrationResponse respose;
    MessageHeader header;
    for (int i = 0; i < requestedservice.size(); i++)
    {
        auto service = _providedServices.find(requestedservice.at(i));
        for (auto it = service->second.begin(); it != service->second.end(); it++)
        {
            Ip *ip = respose.add_ip();
            *ip = *it;
            respose.add_service(requestedservice.at(i));
        }
    }
    std::string resposeS = respose.SerializeAsString();
    header.set_request_size(resposeS.size());
    header.set_arg_size(0);

    std::string headerS = header.SerializeAsString();
    std::string headerSizeS;
    if (!uintToString(headerS.size(), headerSizeS, 4)) // 数据太多了
    {
        conn->shutdown();
        return false;
    }

    conn->send(headerSizeS);
    conn->send(headerS);
    conn->send(resposeS);
    return true;
}
/*记录请求服务与提供的服务，并向其他节点跟新*/
void rpc::ServiceRegistrationCente::updateService(const muduo::net::TcpConnectionPtr &conn, const RegistrationRequest &request)
{
    const google::protobuf::RepeatedPtrField<std::string> requestedservice = request.requestedservice();
    const google::protobuf::RepeatedPtrField<std::string> providedServices = request.providedservice();
    if (_refCount.find(request.nginxip()) != _refCount.end())
    {
        _refCount[request.nginxip()]++;
        conn->setContext(request);
    }
    else
    {
        for (int i = 0; i < providedServices.size(); i++)
        {
            _providedServices[providedServices[i]].insert(request.nginxip());
            for (auto it = _requestedServices[providedServices[i]].begin(); it != _requestedServices[providedServices[i]].end(); it++)
            {
                updateNodeService(conn, request.nginxip(), providedServices[i],true);
            }
        }
        _refCount[request.nginxip()] = 1;
    }
    for (int i = 0; i < requestedservice.size(); i++)
    {
        _requestedServices[requestedservice[i]].insert(conn);
    }
}
void rpc::ServiceRegistrationCente::updateNodeService(const muduo::net::TcpConnectionPtr &conn, const Ip &ip, const std::string& serviceName, bool meothod)
{
    MessageHeader header;
    Request request;
    UpdateNodeServiceArg arg;
    arg.set_servicename(serviceName);
    arg.set_allocated_ip(ip.New());
    request.set_servicename("updateNodeService");
    if(meothod)
    {
        request.set_methodname("addNodeService");
    }
    else
    {
        request.set_methodname("delNodeService");
    }
    std::string requestS = request.SerializeAsString();
    std::string argS = arg.SerializeAsString();
    std::string headerS = header.SerializeAsString();
    header.set_request_size(requestS.size());
    header.set_arg_size(argS.size());
    std::string headerSizeS;
    uintToString(headerS.size(), headerSizeS, 4);
    conn->send(headerSizeS);
    conn->send(header.SerializeAsString());
    conn->send(requestS);
    conn->send(argS);
}
/*
非法字符串返回-1
*/
int rpc::ServiceRegistrationCente::stringToUint(const std::string &str)
{
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            ans = ans * 10 + (str[i] - '0');
        }
        else
        {
            return -1;
        }
    }
    return ans;
}

bool rpc::ServiceRegistrationCente::uintToString(unsigned int num, std::string &str, int len)
{
    str.clear();
    do
    {
        str += (num % 10 + '0');
        num /= 10;
    } while (num);
    if (str.size() > len)
        return false;
    while (str.size() != len)
    {
        str.insert(str.begin(), '0');
    }
    return true;
}
