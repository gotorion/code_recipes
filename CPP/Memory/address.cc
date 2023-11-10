#include <iostream>

class A {
public:
    virtual void func1() {

    }
};

class B {
public:
    virtual void func2() {

    }
};

/* class C : public A, public B { */
/* 谁先被继承，谁就在内存的低地址部分，也即更接近C类部分 */
class C : public B, public A {
public:
    virtual void func3() {

    }
};
int main()
{
    C * c = new C();
    printf("%p\n", c);
    A * a = static_cast<A*>(c);
    printf("%p\n", a);
    B * b = static_cast<B*>(c);
    printf("%p\n", b);
    /* std::cout << sizeof(A) << std::endl; */
    /* std::cout << sizeof(B) << std::endl; */
    /* std::cout << sizeof(C) << std::endl; */
    /* A *pa = new C(); */
    /* std::cout << typeid(pa).name() << std::endl; */
    return 0;
}

