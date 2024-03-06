#include <iostream>

template<typename T>
void print(T& t) {
    std::cout << t << std::endl;
}

template <typename T1, typename T2>
void print(T1&& t1, T2&& t2) {
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << "模板推导" << std::endl;
}

template <typename T1, int>
void print(T1&& t1, int t2) {
    std::cout << "偏特化" << std::endl;
}

int main() {
    int x = 10;
    print(x, 10);
    print(x, "hello");
}