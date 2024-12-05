#include "serviceRegistrationCente.h"

rpc::ServiceRegistrationCente::ServiceRegistrationCente(const muduo::net::InetAddress& address):
    _server(&_loop,address,"ServiceRegistrationCente")
{
    _server.setMessageCallback(std::bind(MessageCallback,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
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
bool rpc::ServiceRegistrationCente::parseRequest(const muduo::net::TcpConnectionPtr &conn,muduo::net::Buffer *buffer, RegistrationRequest &request)
{
    int headerSize=0;
    MessageHeader header;

    if(buffer->readableBytes()<4)
    {
        return false;
    }
    if((headerSize=stringToUint(std::string(buffer->peek(),buffer->peek()+4)))<=0)
    {
        conn->shutdown();
    }
    if(!header.ParseFromArray(buffer->peek()+4,headerSize))
    {
        conn->shutdown();
    }

    if(buffer->readableBytes()<headerSize+header.request_size())
    {
        return false;
    }
    
    return false;
}

bool rpc::ServiceRegistrationCente::HandleRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &)
{
    return false;
}

bool rpc::ServiceRegistrationCente::respondToRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &)
{
    return false;
}

bool rpc::ServiceRegistrationCente::expandService(const RegistrationRequest &)
{
    return false;
}
/*
非法字符串返回-1
*/
int rpc::ServiceRegistrationCente::stringToUint(const std::string &str)
{
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]<='9'&&str[i]>='0')
        {
            ans=ans*10+(str[i]-'0');
        }else{
            return -1;
        }
    }
    return ans;
}
