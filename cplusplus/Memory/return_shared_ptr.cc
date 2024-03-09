#include <memory>
#include <iostream>
using namespace std;

class Base {
    public:
    void print() {
        std::cout << data_ << std::endl;
    }
    int data_{10};
};

std::shared_ptr<Base> func() {
    return std::make_shared<Base>();
}

int main() {
    std::shared_ptr<Base> ptr = func();
    ptr->print();
    return 0;
}