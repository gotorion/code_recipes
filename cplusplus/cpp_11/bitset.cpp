#include <bitset>
#include <iostream>
int main() {
    std::bitset<8> bit("10001010");
    std::cout << "length of bit = " << bit.size() << std::endl;
    std::cout << "bit 1 = " << bit[1] << std::endl;
    std::cout << "to string, result = " << bit.to_string() << std::endl;
    std::cout << "! then to string, result = " << (~bit).to_string() << std::endl;
    return 0;
}
