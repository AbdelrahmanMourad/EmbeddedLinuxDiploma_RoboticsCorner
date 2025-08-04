#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>
 
template<typename T>
class ThreadSafeQueue {
private:
    std::queue<T> _queue;
    std::mutex _mutex;
    std::condition_variable _cond;
 
public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(_mutex);

        _queue.push(value);

        _cond.notify_one(); // Notify one waiting thread
    }
 
    T pop() {
        std::unique_lock<std::mutex> lock(_mutex);

        // Wait until the queue is not empty. The wait() call

        // atomically releases the lock and blocks the thread.

        // It re-acquires the lock on wakeup.

        _cond.wait(lock, [this]{ return !_queue.empty(); });

        T value = _queue.front();

        _queue.pop();

        return value;
    }
};
 
void producer(ThreadSafeQueue<int>& queue) {

    for (int i = 0; i < 5; ++i) {

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout << "Producer: Pushing " << i << std::endl;

        queue.push(i);
    }
}
 
void consumer(ThreadSafeQueue<int>& queue) {

    for (int i = 0; i < 5; ++i) {

        int value = queue.pop();

        std::cout << "Consumer: Popped " << value << std::endl;
    }
}
 
int main() {

    ThreadSafeQueue<int> myQueue;

    std::thread producerThread(producer, std::ref(myQueue));

    std::thread consumerThread(consumer, std::ref(myQueue));

    producerThread.join();

    consumerThread.join();

    return 0;

}
 