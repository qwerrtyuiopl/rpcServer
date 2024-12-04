#include "serviceRegistrationCente.h"

rpc::ServiceRegistrationCente::ServiceRegistrationCente(const muduo::net::InetAddress& address):
    _server(&_loop,address,"ServiceRegistrationCente")
{
    _server.setMessageCallback(std::bind(MessageCallback,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
}

void rpc::ServiceRegistrationCente::MessageCallback(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp)
{
    
}
