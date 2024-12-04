#pragma once
#include <muduo/net/TcpConnection.h>
#include <rpcService.h>
namespace rpc
{
    class RpcChannel
    {
    public:
        virtual bool send(const RpcMethod &method, MessagePtr arg);
    };
}