#include <iostream>
#include <set>
int main()
{
    std::set<int> set1{1, 2, 3, 4, 5};
    std::set<int> set2{4, 5, 3, 2, 1};
    if (set1 == set2) {
        std::cout << "set1 == set2" << std::endl;
    } else {
        std::cout << "set1 != set2" << std::endl;
    }
    return 0;
}

