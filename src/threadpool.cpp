#include <threadpool.h>

Threadpool::Threadpool(int numThreads) : _numThreads(numThreads)
{}

void Threadpool::start()
{
    for(int i = 0; i < _numThreads; i++)
        _pool.push_back(std::thread(executeJobs));

    while(true)
    {
        if(_jobQueue.empty())
        {
            shutDown();
            break;
        }
    }
}

void Threadpool::executeJobs()
{
    while(!_jobQueue.empty())
    {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(_queueMutex);
            _condition.wait(lock, []{return (!_jobQueue.empty() || _shouldTerminate);});
            if(_jobQueue.empty())
                return;
            job = _jobQueue.back();
            _jobQueue.pop_back();
        }
        job();
    }
}

void Threadpool::addJob(std::function<void()> job)
{
    _jobQueue.push_back(job);
}

void Threadpool::shutDown()
{
    _shouldTerminate = true;

    _condition.notify_all();

    for(std::thread &every_thread : _pool)
    {   every_thread.join();}

    _pool.clear();
}