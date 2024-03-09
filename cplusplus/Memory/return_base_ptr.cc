#include <memory>
#include <functional>
#include <iostream>
class Base {
    public:
        virtual void print() {
            std::cout << "Base" << std::endl;
        }
};

class Derived : public Base {
    public:
        void print() {
            std::cout << "Derived" << std::endl;
        }
};

std::shared_ptr<Base> func() {
    static std::shared_ptr<Derived> derived = 
        std::make_shared<Derived>();
    return derived;
}

int main() {
    auto base = func();
    base->print();
    return 0;
}