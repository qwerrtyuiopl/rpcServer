#pragma once
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <google/protobuf/message.h>
#include <memory>
#include <rpcMethod.h>
namespace rpc
{
    using MessagePtr = std::shared_ptr<google::protobuf::Message>;
    class RpcService
    {
    public:
        RpcService(const std::string &name) : _name(name)
        {
        }
        const std::string &get_name() { return _name; }
        virtual RpcMethod *get_method(std::string &name) = 0;
    private:
        const std::string _name;
    };
}