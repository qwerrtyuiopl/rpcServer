#include "rpcThreadPool.h"

rpc::RpcThread &rpc::RpcThreadPool::get_RpcThread()
{
    pid_t currentPid=muduo::CurrentThread::tid();
    if(_threadIds.find(currentPid)!=_threadIds.end())
    {
        for(auto it=_rpcThreadMap.begin();it!=_rpcThreadMap.end();it++)
        {
            if(it->second.get_pid()==currentPid)
            {
                return _rpcThreadMap[it->first];
            }
        }
        //what happen?
        exit(-1);
    }
    if(_rpcThreadMap.find(currentPid)==_rpcThreadMap.end())
    {
        _rpcThreadMap[currentPid].start();
    }
    return _rpcThreadMap[currentPid];
}