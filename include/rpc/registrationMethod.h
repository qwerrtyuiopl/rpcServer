#include <rpcMethod.h>

namespace rpc
{
    class AddServiceConnMethod : public RpcMethod
    {
    public:
        AddServiceConnMethod();
        MessagePtr arg() override;
    };
}