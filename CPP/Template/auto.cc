#include <iostream>
void print(auto x) { // C++20 support
    std::cout << x << std::endl;
}

int main() {
    print("Hello");
    return 0;
}