#include <memory>
#include <google/protobuf/message.h>
namespace rpc
{
    using MessagePtr = std::shared_ptr<google::protobuf::Message>;
    class method
    {
    public:
        method(const void (*m)(MessagePtr, MessagePtr, MessagePtr)) : _method(m) {}
        virtual MessagePtr request() = 0;
        virtual MessagePtr Response() = 0;
        virtual MessagePtr arg() = 0;
        const void (*_method)(MessagePtr, MessagePtr, MessagePtr);
    };
}