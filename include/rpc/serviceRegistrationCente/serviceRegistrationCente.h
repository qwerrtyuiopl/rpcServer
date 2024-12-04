#include <vector>
#include <rpcService.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <Ip.pb.h>
#include <oneTBB/oneapi/tbb/concurrent_hash_map.h>
#include<functional>

namespace rpc
{
    class ServiceRegistrationCente
    {
    public:
        ServiceRegistrationCente(const muduo::net::InetAddress& address);
        void setThreadNum(unsigned int num){_server.setThreadNum(num);}
        void start(){_loop.loop();}
    private:
        void MessageCallback(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);

    private:
        muduo::net::TcpServer _server;
        muduo::net::EventLoop _loop;
        oneapi::tbb::concurrent_hash_map<RpcService, std::vector<Ip>> _serviceIp;
    };
}