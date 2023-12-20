#include <iostream>
#include <queue>
int main()
{
    std::queue<int> que;
    if (que.front()) {
        std::cout << "que.front() = " << que.front() << std::endl;
    } else {
        std::cout << "que is empty" << std::endl;
    }
    return 0;
}

