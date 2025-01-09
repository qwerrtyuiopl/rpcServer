#pragma once
#include <pthread.h>
#include <vector>
#include <functional>
#include <atomic>
#include <semaphore.h>
#include <muduo/base/CurrentThread.h>
#include <muduo/base/Mutex.h>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
namespace rpc
{
    class RpcThread
    {
    public:
        RpcThread(const RpcThread &) = delete;
        RpcThread &operator=(const RpcThread &) = delete;
        RpcThread()
        {
            sem_init(&_sem, 0, 0);
        }
        bool isInThread() const { return _threadId == muduo::CurrentThread::tid(); }
        bool runInThread(std::function<void()> cb)
        {
            if (isInThread())
            {
                cb();
            }
            else if (!_isStart)
            {
                return false;
            }
            else
            {
                muduo::MutexLockGuard guardLock(_lock);
                _functions.push_back(std::move(cb));
            }
            return true;
        }
        pid_t get_pid() const
        {
            if (_isStart)
                return _threadId;
            return -1;
        }
        /*
        线程不安全
        */
        void start()
        {
            if (!_isStart)
            {
                if (pthread_create(&_thread, nullptr, &run, (void *)this))
                {
                    exit(-1);
                }
                sem_wait(&_sem);
            }
        }
        void stop()
        {
            _isStart = false;
            pthread_join(_thread, nullptr);
        }

    private:
        static void *run(void *thread)
        {
            ((RpcThread *)thread)->task();
            return nullptr;
        }
        void task()
        {
            _threadId = muduo::CurrentThread::tid();
            _isStart = true;
            sem_post(&_sem);
            while (_isStart || !_functions.empty())
            {
                std::vector<std::function<void()>> functions;
                while (!_functions.size())
                    usleep(10);
                _functions.swap(functions); // 加锁？
                for (auto it = functions.begin(); it != functions.end(); it++)
                {
                    (*it)();
                }
            }
        }

    private:
        std::vector<std::function<void()>> _functions;
        pthread_t _thread;
        std::atomic_bool _isStart;
        pid_t _threadId;
        sem_t _sem;
        muduo::MutexLock _lock;
    };
    class RpcThreadPool
    {
    public:
        // 禁止拷贝和赋值
        RpcThreadPool(const RpcThreadPool &) = delete;
        RpcThreadPool &operator=(const RpcThreadPool &) = delete;

        // 获取ThreadPool单例
        static RpcThreadPool &getInstance()
        {
            static RpcThreadPool instance; // 局部静态变量，线程安全且只初始化一次
            return instance;
        }
        RpcThread &get_RpcThread();

    private:
        RpcThreadPool()
        {
        }
        ~RpcThreadPool()
        {
        }
        RpcThreadPool(RpcThreadPool &&) = delete;

    private:
        std::unordered_map<pid_t, RpcThread> _rpcThreadMap;
        std::unordered_set<pid_t> _threadIds;
    };

}