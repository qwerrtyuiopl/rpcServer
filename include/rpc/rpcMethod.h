#pragma once
#include <memory>
#include <google/protobuf/message.h>
#include<rpcService.h>
namespace rpc
{
    using MessagePtr = std::shared_ptr<google::protobuf::Message>;
    class RpcMethod
    {
    public:
        RpcMethod(void (*m)(MessagePtr, MessagePtr),RpcService* service) : _method(m),_service(service) {}
        const RpcService& service()const{return *_service;}
        void run(MessagePtr Response, MessagePtr arg);
        virtual MessagePtr Response() = 0;
        virtual MessagePtr arg() = 0;
    private:
        void (*_method)(MessagePtr, MessagePtr);
        RpcService* _service;
    };
}