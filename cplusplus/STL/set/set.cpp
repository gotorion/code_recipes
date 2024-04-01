#include <set>
#include <iostream>

int main() {
    std::set<int> mySet{3, 4, 12, -34, 29};
    for (auto iter = std::begin(mySet); iter != std::end(mySet); ++iter) {
        std::cout << "num = " << *iter << " ";
    } 
    std::cout << std::endl;
    return 0;
}