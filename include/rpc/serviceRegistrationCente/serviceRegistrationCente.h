#pragma once
#include <vector>
#include <rpcService.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <Ip.pb.h>
#include <oneTBB/oneapi/tbb/concurrent_unordered_map.h>
#include <oneTBB/oneapi/tbb/concurrent_unordered_set.h>
#include <functional>
#include <registrationMessage.pb.h>
#include <messageHeader.pb.h>

namespace rpc
{
    class ServiceRegistrationCente
    {
    public:
        ServiceRegistrationCente(const muduo::net::InetAddress &address);
        void setThreadNum(unsigned int num) { _server.setThreadNum(num); }
        void start();

    private:
        void MessageCallback(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);
        bool parseRequest(const muduo::net::TcpConnectionPtr &,muduo::net::Buffer *, RegistrationRequest &);
        bool HandleRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &);
        bool respondToRequest(const muduo::net::TcpConnectionPtr &, const RegistrationRequest &);
        bool expandService(const RegistrationRequest &);
        int stringToUint(const std::string& str);
    private:
        muduo::net::TcpServer _server;
        muduo::net::EventLoop _loop;
        oneapi::tbb::concurrent_unordered_map<RpcService, oneapi::tbb::concurrent_unordered_set<Ip>> _service;
    };
}