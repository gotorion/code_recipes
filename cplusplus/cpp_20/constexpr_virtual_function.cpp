#include <iostream>
struct X1 {
    virtual int f() const = 0;
};

struct X2 : public X1 {
    constexpr virtual int f() const { return 2; }
};

struct X3 : public X2 {
    virtual int f() const { return 3; }
};

int main (int argc, char *argv[]) {
    std::cout << X2().f() << std::endl;
    std::cout << X3().f() << std::endl;;
    return 0;
}
