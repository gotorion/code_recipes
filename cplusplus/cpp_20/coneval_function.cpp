#include <iostream>
consteval int sqr(int n) {
    // must generate a constant value
    return n * n;
}

int main (int argc, char *argv[]) {
    constexpr int r = sqr(100); 
    return 0;
}
