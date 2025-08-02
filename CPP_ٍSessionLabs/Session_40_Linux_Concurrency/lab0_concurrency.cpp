/*  ========================================================================================================
    CONCURRENCY LIBRARY IN C/C++
    ========================================================================================================
        in C    => pthread
        in C++  => concurrency library as a wrapper layer over the pthread

        what we will study in concurrency:
            1-   How to make a thread.
            2-   How to synchronize more than one thread.
            3-   How to solve "data racing" problems.
            4-   How to work asynchronous programming.


        Q1): Where to use concurrency?
            ->  As long as it's C++, then it works on any posix-compatible platform like Linux, Windows, and Mac.
            ->  (Concurrency is Generic)

        Q2): Is there a prerequisites before i compile program with threads?
            ->  in old windows/ubuntu you may need to include the c library pthread manually on terminal:
                    "g++ lab.cpp -o lab.exe -lpthread"
    ========================================================================================================
*/

/*
========================================================================================================
C++ Concurrency Library - Summary & Key Concepts
========================================================================================================
| - C++ provides a high-level concurrency library (wrapper over C pthreads) for multi-threading.
| - Main features:
|     1. Creating threads using std::thread.
|     2. Synchronizing threads (mutexes, locks, etc.).
|     3. Solving data races (protecting shared data).
|     4. Asynchronous programming (futures, async).
|
| - Platform support: Works on any POSIX-compatible OS (Linux, Windows, Mac).
| - Compilation: May require linking with pthread on some systems (e.g., g++ lab.cpp -o lab.exe -lpthread).
|
| Example Concepts:
| - std::thread: Create and manage threads.
| - std::thread::hardware_concurrency(): Query number of hardware threads.
| - std::this_thread::sleep_for(): Pause thread for a duration.
| - Thread joining: thread.join() blocks main thread until the thread finishes.
|     * If you join a thread before starting others, main thread is blocked and can't start more threads.
|     * Always start all threads before joining them to allow concurrent execution.
|
| - Data races: Occur when multiple threads access shared data without synchronization.
| - Synchronization: Use mutexes, locks, and atomic variables to protect shared data.
|
| - Asynchronous programming: Use std::async, std::future for tasks that run in the background.
|
| Best Practices:
| - Start all threads before joining.
| - Protect shared resources.
| - Use sleep_for for demonstration, but avoid in production for synchronization.
| - Prefer high-level C++ concurrency features over manual
========================================================================================================
*/

#include <iostream>
#include <thread> // thread: """threads/concurrency""" in cpp. wrapper layer for C pthread library.
#include <chrono> // chrono: """time/clock""" in cpp.

void thread_func()
{
    while (1)
    {
        auto n = std::thread::hardware_concurrency();                               // get the hardware resources, how many threads available.
        std::cout << "Number of threads supported by hardware: " << n << std::endl; // Print info.
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));               // go to block state and wait for one second.
    }
}

void second_thread()
{
    while (1)
    {
        std::cout << "I'm the second thread\n";                      // Print info.
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // go to block state for half second.
    }
}

void main1();
void main2();
/******************************************************************************************************************/
int main()
{

    // main1();
    main2();

    return 0;
}
/******************************************************************************************************************/
void main1()
{
    // object of thread class, the constructors take function as parameter that return void.
    std::thread thread1(thread_func);
    thread1.join(); // <-- Main thread waits here until thread1 finishes (never, because it's infinite)

    // std::thread thread2(std::move(thread1));
    std::thread thread2(second_thread);
    thread2.join(); // The thread join the process.
}

void main2()
{
    // object of thread class, the constructors take function as parameter that return void.
    std::thread thread1(thread_func); // Run
    // std::cout<<"_____after thread1.\n";
    std::thread thread2(second_thread); // Run
    // std::cout<<"_____after thread2.\n";
    // std::thread thread2(std::move(thread1));

    thread1.join(); // The thread join the process.
    // std::cout<<"_____after thread1.join()\n";
    thread2.join(); // The thread join the process.
    // std::cout<<"_____after thread2.join()\n";
}
