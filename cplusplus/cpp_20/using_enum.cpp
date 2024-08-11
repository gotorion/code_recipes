#include <iostream>
enum class Color {
    Red,
    Green,
    Blue,
};

int main (int argc, char *argv[]) {
    using enum Color;
    switch (auto c = Red; c) {
        case Red:
            std::cout << "red" << std::endl;
            break;
        case Blue:
            break;
        default:
            break;
    }
    return 0;
}
