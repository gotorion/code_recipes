#include <mutex>
#include <iostream>
#include <shared_mutex>
#include <thread>
class ThreadSafeCounter
{
public:
    ThreadSafeCounter() = default;
    ~ThreadSafeCounter() = default;

    uint32_t get() const
    {
        std::shared_lock lock(mutex_);
        return value_;
    }
    void increment()
    {
        std::unique_lock lock(mutex_);
        ++value_;
    }
    void reset()
    {
        std::unique_lock lock(mutex_);
        value_ = 0;
    }

private:
    mutable std::shared_mutex mutex_;
    uint32_t value_;
};

int main()
{
    ThreadSafeCounter counter;
    auto increment_and_print = [&counter]()
    {
        for (int i{}; i != 3; ++i)
        {
            counter.increment();
            std::cout << std::this_thread::get_id() << ' ' << counter.get() << std::endl;
        }
    };
    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    return 0;
}