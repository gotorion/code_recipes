#include <utility>
#include <iostream>

template<typename T>
void print(T & t)
{
    std::cout << "Lvalue ref" << std::endl;
}

template<typename T>
void print(T && t)
{
    std::cout << "Rvalue ref" << std::endl;
}

template<typename T>
void testForward(T && v)
{
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
    std::cout << "=========" << std::endl;
}

int main() {
    int x = 1;
    testForward(x);
    testForward(std::move(x));
    return 0;
}
