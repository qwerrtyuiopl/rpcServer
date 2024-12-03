#include <service.h>

bool rpc::Service::run(const std::string &functionName, MessagePtr Request, MessagePtr Response)
{
    if (_function.find(functionName) != _function.end())
    {
        return _function[functionName](Request, Response);
    }
    return false;
}

void rpc::Service::add_function(const std::string &functionName, std::function<bool(MessagePtr Request, MessagePtr Response)> function)
{
    _function[functionName] = std::move(function);
}

void rpc::Service::delete_function(const std::string &functionName)
{
    if (_function.find(functionName) != _function.end())
    {
        _function.erase(functionName);
    }
}

std::vector<std::string> rpc::Service::get_functionNames()
{
    std::vector<std::string> functionNames;
    for(auto it=_function.begin();it!=_function.end();it++)
    {
        functionNames.push_back(it->first);
    }
    return functionNames;
}
