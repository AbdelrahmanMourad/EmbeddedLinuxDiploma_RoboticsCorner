#include <iostream>
#include <thread>
#include <chrono>

// global variable
// std::string machine_ip("10.20.0.100");

void Display(std::string machine_ip, int count)
{
    while (1)
    {
        std::cout << "Machine ip: " << machine_ip << "\tcount= " << count << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    // in case we want to make local variable and pass it.
    std::string machine_ip("10.20.0.100");
    int cout{5};
    std::thread display_thread([])
    /*Thread is variadic template, 1st parameter is the function, all the following parameters are the function parameters (so they actually must match).*/
    std::thread display_thread(Display /*func/callable/invokable*/, machine_ip /*function paramter*/, count);
    display_thread.join();


    return 0;
}

class thread
{
public:
    template <class callable, class T>
    thread(callable fun_, T.../*variadic template takes any number of paramteters*/) {}

};