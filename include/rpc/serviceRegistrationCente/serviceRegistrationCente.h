#pragma once
#include <vector>
#include <rpcService.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <Ip.pb.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <registrationMessage.pb.h>
#include <messageHeader.pb.h>
#include<request.pb.h>
#include<updateNodeServiceArg.pb.h>

namespace rpc
{
    class ServiceRegistrationCente
    {
    public:
        ServiceRegistrationCente(const muduo::net::InetAddress &address);
        void start();

    private:
        void MessageCallback(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);
        void ConnectionCallback(const muduo::net::TcpConnectionPtr &);
        bool parseRequest(const muduo::net::TcpConnectionPtr &,muduo::net::Buffer *, RegistrationRequest &);
        bool handleRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &);
        bool respondToRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &);
        void updateService(const muduo::net::TcpConnectionPtr &,const RegistrationRequest &);
        void updateNodeService(const muduo::net::TcpConnectionPtr &,const Ip&,const std::string&, bool);
        int stringToUint(const std::string& str);
        bool uintToString(unsigned int num,std::string& str,int len);
    private:
        muduo::net::TcpServer _server;
        muduo::net::EventLoop _loop;
        std::unordered_map<std::string, std::unordered_set<Ip>> _providedServices;
        std::unordered_map<std::string, std::unordered_set<const muduo::net::TcpConnectionPtr>> _requestedServices;
        std::unordered_map<Ip, int> _refCount;
    };
}