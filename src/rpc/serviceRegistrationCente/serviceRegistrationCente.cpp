#include "serviceRegistrationCente.h"

rpc::ServiceRegistrationCente::ServiceRegistrationCente(const muduo::net::InetAddress &address) : _server(&_loop, address, "ServiceRegistrationCente")
{
    _server.setMessageCallback(std::bind(MessageCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void rpc::ServiceRegistrationCente::start()
{
    _server.start();
    _loop.loop();
}

void rpc::ServiceRegistrationCente::MessageCallback(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp)
{
}
/*
解析错误关闭连接(数据不足保留数据不会关闭连接)
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

bool rpc::ServiceRegistrationCente::handleRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &)
{
    return false;
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

void rpc::ServiceRegistrationCente::handleService(const muduo::net::TcpConnectionPtr &conn, const RegistrationRequest &request)
{
    const google::protobuf::RepeatedPtrField<std::string> requestedservice = request.requestedservice();
    const google::protobuf::RepeatedPtrField<std::string> providedServices = request.providedservice();
    for (int i = 0; i < requestedservice.size(); i++)
    {
        _requestedServices[requestedservice[i]].insert(conn);
    }
    for (int i = 0; i < requestedservice.size(); i++)
    {
        _requestedServices[requestedservice[i]].insert(conn);
    }
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
