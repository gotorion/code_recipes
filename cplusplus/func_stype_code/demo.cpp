#include <iostream>
void say_hello()
{
    std::printf("Hello world!\n");
}

void call_twice(void func())
{
    func();
    func();
}

template <typename T>
decltype(auto)
call_three_times(T &&func)
{
    func();
    func();
    func();
}

int main()
{
    // call_twice(say_hello);
    call_three_times(say_hello);
    if (std::is_same_v<decltype(call_three_times(say_hello)), void>)
    {
        std::cout << "all returns void" << std::endl;
    }
    return 0;
}