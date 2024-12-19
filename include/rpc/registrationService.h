#include <rpcService.h>

namespace rpc
{
    class RegistrationService : public RpcService
    {
    public:
        RegistrationService();
        RpcMethod *get_method(std::string &name) override;
    private:
    };
}