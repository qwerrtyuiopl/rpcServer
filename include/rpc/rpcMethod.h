#pragma once
#include <memory>
#include <google/protobuf/message.h>
#include<rpcService.h>
#include<functional>

namespace rpc
{
    using MessagePtr = std::shared_ptr<google::protobuf::Message>;
    class RpcMethod
    {
    public:
        RpcMethod(std::function<void(MessagePtr)> m,RpcService* service) : _method(m),_service(service) {}
        const RpcService& service()const{return *_service;}
        void operator[](MessagePtr arg){_method(arg);}
        virtual MessagePtr arg() = 0;
    private:
        std::function<void(MessagePtr)>_method;
        RpcService* _service;
    };
}