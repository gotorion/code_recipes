#include <iostream>
#include <memory>
class Base {
public:
    void print() const {
        std::cout << "Hello Base" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Base> uPointer = std::make_unique<Base>();
    uPointer->print();
    std::shared_ptr<Base> sPointer(uPointer.get()); // double free, error
    sPointer->print();
    return 0;

}

