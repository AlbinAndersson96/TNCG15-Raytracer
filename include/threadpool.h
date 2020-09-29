#pragma once

#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <condition_variable>

#include <scene.h>

class Threadpool
{
    public:
        Threadpool(int numThreads);

        void start();
        void addJob(std::function<void()> job);
        void shutDown();

    private:
        inline static void executeJobs();

        inline static std::mutex _queueMutex;
        inline static std::condition_variable _condition;
        
        inline static std::vector<std::thread> _pool;
        inline static std::vector<std::function<void()>> _jobQueue;

        int _numThreads;
        inline static bool _shouldTerminate;
};