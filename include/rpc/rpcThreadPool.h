#include <pthread.h>
#include <vector>
#include <functional>
#include <atomic>
#include <semaphore.h>
#include <muduo/base/CurrentThread.h>
#include <muduo/base/Mutex.h>
namespace rpc
{
    class RpcThread
    {
    public:
        RpcThread()
        {
            sem_init(&_sem, 0, 0);
        }
        bool isInThread() const { return _threadId == muduo::CurrentThread::tid(); }
        bool runInThread(std::function<void()> cb)
        {
            if (isInThread)
            {
                cb();
            }
            else if(!_isStart)
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
            _isStart=false;
            pthread_join(_thread,nullptr);
        }
    private:
        static void *run(void *thread)
        {
            ((RpcThread *)thread)->task();
        }
        void task()
        {
            _threadId = muduo::CurrentThread::tid();
            _isStart = true;
            sem_post(&_sem);
            while (_isStart || !_functions.empty())
            {
                std::vector<std::function<void()>> functions;
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
        std::atomic_bool _isStart = false;
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