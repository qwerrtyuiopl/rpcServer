#pragma once
#include <rpcService.h>
#include <rpcChannel.h>

namespace rpc
{
    class RpcServiceStub
    {
    public:
        RpcServiceStub(RpcService *service, RpcChannel *channel) : _service(service), _channel(channel) {}

    private:
        RpcService *_service;
        RpcChannel *_channel;
    };
}