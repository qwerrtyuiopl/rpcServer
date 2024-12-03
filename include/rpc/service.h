#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <google/protobuf/message.h>
#include <memory>
namespace rpc
{
    using MessagePtr=std::shared_ptr<google::protobuf::Message>;
    class Service
    {
    public:
        const std::string &get_name() { return _name; }
        std::vector<std::string> get_functionNames();
        bool run(const std::string &functionName, MessagePtr Request, MessagePtr Response);
        void add_function(const std::string &functionName,std::function<bool(MessagePtr Request, MessagePtr Response)> function);
        void delete_function(const std::string &functionName);
    protected:
        Service(const std::string &name) : _name(name)
        {
        }

    private:
        const std::string _name;
        std::unordered_map<std::string, std::function<bool(MessagePtr Request, MessagePtr Response)>> _function;
    };
    /*
    通过工厂创建不同的Server,Server_Stub
    */
}