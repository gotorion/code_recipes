#include <iostream>
class A
{
public:
    A() = default;
    ~A() = default;

    A(const A &rhs)
    {
        std::cout << "copy construct" << std::endl;
    }
    const A &operator=(const A &rhs)
    {
        std::cout << "A was copyed" << std::endl;
        *this = rhs;
        return *this;
    }
    void print()
    {
        std::cout << "A object" << std::endl;
    }
};

class B
{
public:
    B() = default;
    ~B() = default;
    const B &operator=(const B &rhs)
    {
        *this = rhs;
        std::cout << "B was copyed" << std::endl;
        return *this;
    }
    void print()
    {
        std::cout << "B object" << std::endl;
    }
};

class C
{
public:
    C(A a, B b)
        : a_(std::move(a)), b_(std::move(b)) // better construct use std::move
    {
    }

private:
    A a_;
    B b_;
};

int main()
{
    A a;
    B b;
    C c(a, b);          // two copy construct
    C otherC(A a, B b); // no copy construct
}