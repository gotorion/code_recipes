#include <iostream>
#include <vector>
int main (int argc, char *argv[]) {
    auto f = []<typename T>(std::vector<T> v) {
        for (auto elem : v) {
            std::cout << elem << std::endl;
        }
    };
    f(std::vector<int>{1, 2, 3, 4});
    f(std::vector<double>{1, 2, 3, 4});
    return 0;
}
