#pragma once
#include <string>
#include<unordered_map>
namespace rpc
{
#define CONFIGPATH "./RpcConfig.fig"

    class Config
    {
    public:
        Config(const Config &) = delete;
        Config &operator=(const Config &) = delete;
        static Config &getInstance()
        {
            static Config instance;
            return instance;
        }
        const std::string getVal(const std::string& key,bool& flag);
        /*
        会结束程序
        */
        const std::string getVal(const std::string& key);
    private:
        Config(std::string rpcConfig = CONFIGPATH);
        ~Config() = default;

        std::unordered_map<std::string,std::string> _config;
    };
}