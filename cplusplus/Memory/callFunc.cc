#include <iostream>
class A {
public:
    virtual void func() {
        std::cout << "A::func()" << std::endl;
    }

    void func1() {
        std::cout << "A::func1()" << std::endl;
    }
};

class B : public A {
public:
    void func() {
        std::cout << "B::func()" << std::endl;
    }
};

int main() {
    B * b = new B();
    // 可不可以直接用b来调用A中的func()?
    b->A::func(); // 虚函数是在运行时进行的，b可以只使用静态联编
    b->func();
    return 0;
}

