#pragma once
#include <rpcService.h>
#include <rpcServiceStub.h>
#include <muduo/net/TcpServer.h>
#include <vector>
namespace rpc
{
    class RpcServer
    {
    public:
    private:
        muduo::net::TcpServer _server;
        std::vector<RpcService*> _service;
        std::vector<RpcServiceStub*> _serviceStub;

    };
}
