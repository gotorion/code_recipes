#include <iostream>
#include <memory>
using namespace std;

std::unique_ptr<int> testFunc() {
    std::unique_ptr<int> local = std::make_unique<int>(2);
    return local;
}

int main()
{
    std::unique_ptr<int> ret = testFunc();

    return 0;
}

