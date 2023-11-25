#include <iostream>
using namespace std;

template <typename ...Args>
void print(Args ...args) {
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof...args = " << sizeof...(args) << endl;
}

void test0() {
    print();
    print(1, "Hello");
    print(1.1, "Hello", true);
}

void display() {
    cout << endl;
}

template <typename T, typename ...Args>
void display(T t, Args ...args) { // pack
    cout << t << " ";
    display(args...); // unpack
}

void test2() {
    display();
    display(1.1, "Hello", false, 20);
}

int main() {
    // test0();
    test2();
    return 0;
}