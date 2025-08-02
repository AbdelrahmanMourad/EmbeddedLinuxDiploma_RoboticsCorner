
/*
==========================================================================================================
Mutex:
    Deadlocks:  سيب وانا اسيب



==========================================================================================================
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

/*  both threads use 2 resources, both need to acquire them to work
        example: marker, white_board

    The problem is that this is a bad design, one of the solutions it to design is to: 
        acquire both at the same time, and release them at the same time.
        or can use other data types than mutex: lock_guard
*/

std::mutex mutex_board;
std::mutex mutex_pen;

void thread1()
{
    mutex_board.lock(); // board
    board.use();
    mutex_pen.lock(); // pen
    pen.use();
    mutex_board.unlock();
    mutex_pen.unlock();
}

void thread2()
{
    mutex_pen.lock(); // pen
    pen.use();
    mutex_board.lock(); // board
    board.use();
    mutex_board.unlock();
    mutex_pen.unlock();
}
