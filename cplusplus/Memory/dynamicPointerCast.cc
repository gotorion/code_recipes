#include <iostream>
#include <memory>
class Base {
    public:
        virtual void print() {
            std::cout << "This is Base class" << std::endl;
        }
};

class Derived : public Base {
    public:
        void print() override {
            std::cout << "This is Derived class" << std::endl;
        }
};

int main() {
    using namespace std;
    shared_ptr<Base> basePtr =  make_shared<Derived>();
    auto derivedPtr = dynamic_pointer_cast<Derived>(basePtr);
    if (derivedPtr == nullptr) {
        cout << "derivedPtr is nullptr" << endl;
    } else {
        derivedPtr->print();
    }
    return 0;
}