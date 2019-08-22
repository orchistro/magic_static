#include <mutex>
#include <iostream>
#include <condition_variable>
#include <thread>
#include <unistd.h>
#include <vector>


std::mutex gDisplayMutex;

std::condition_variable gCond;
std::mutex gCondMutex;

class Foo
{
    public:
        Foo()
        {
            for (int i = 0; i < 5; i++)
            {
                {
                    std::scoped_lock sLock(gDisplayMutex);
                    std::cout << "Foo() in the context of threadid " << std::this_thread::get_id() << "\n";
                }
                sleep(1);
            }

            mId = std::this_thread::get_id();
        }

        std::thread::id mId;

};

void threadmain(void)
{
    {
        std::unique_lock sLock(gCondMutex);
        gCond.wait(sLock);
    }

    {
        std::scoped_lock sLock(gDisplayMutex);
        std::cout << "Threadmain: myid:" << std::this_thread::get_id() << " Received signal\n";
    }

    static Foo Foo;

    {
        std::scoped_lock sLock(gDisplayMutex);
        std::cout << "Threadmain: myid:" << std::this_thread::get_id() << " Foo.mId:" << Foo.mId << "\n";
    }
}

int main(void)
{
    std::vector<std::thread> vec;

    for (int i = 0; i < 20; i++)
    {
        vec.emplace_back(threadmain);
    }

    std::cout << "Signaling from main\n";

    gCond.notify_all();

    for (auto& thr : vec)
    {
        thr.join();
    }

    return 0;
}
