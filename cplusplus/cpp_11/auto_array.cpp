#include <iostream>

void func(auto num) {
    std::cout << num << std::endl;
}

int main() {
    int arr[3] = {1, 2, 3} ;
    auto b = arr;
    std::cout << typeid(b).name() << std::endl;

    auto &c = arr;
    std::cout << typeid(c).name() << std::endl;

    func(10);
    return 0;
}