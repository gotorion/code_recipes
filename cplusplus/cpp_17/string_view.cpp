#include <string>
#include <string_view>
#include <iostream>
std::string_view ReturnStringView() {
    std::string str("This is a test string");
    return std::string_view(str);
}

int main() {
    std::string_view view = ReturnStringView();
    std::cout << view << std::endl; // this behavior is undefined
}