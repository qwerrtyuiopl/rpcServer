#include <pthread.h>
#include <vector>
#include <functional>
#include <atomic>
#include <semaphore.h>
#include <muduo/base/CurrentThread.h>
namespace rpc
{
    class Thread
    {
    public:
        Thread()
        {
            if (pthread_create(&_thread, nullptr, &run, (void *)this))
            {
                exit(-1);
            }
            sem_init(&_sem, 0, 0);
            pthread_detach(_thread);
            sem_wait(&_sem);
        }
        bool isInThread() const { return _threadId == muduo::CurrentThread::tid();}
        void runInThread(std::function<void()> cb)
        {
            if (isInThread)
            {
                cb();
            }
            else
        }

    private:
        static void *run(void *thread)
        {
            ((Thread *)thread)->task();
        }
        void task()
        {
            _threadId = muduo::CurrentThread::tid();
            sem_post(&_sem);
            while (isStart)
            {
                std::vector<std::function<void()>> functions;
                _functions.swap(functions);
                for (auto it = functions.begin(); it != functions.end(); it++)
                {
                    (*it)();
                }
            }
        }

    private:
        std::vector<std::function<void()>> _functions;
        pthread_t _thread;
        std::atomic_bool isStart = false;
        pid_t _threadId;
        sem_t _sem;
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

    private:
        RpcThreadPool()
        {
        }
        ~RpcThreadPool()
        {
        }
        RpcThreadPool(RpcThreadPool &&) = delete;
    };

}