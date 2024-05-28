#include <iostream>
#include <string>
#include <memory>

int main() {
    auto uni = std::make_unique<int>(100);
    std::shared_ptr<int> sha1 = std::move(uni);

    std::cout << *sha1 <<  std::endl;
    if (uni.get() == nullptr) {
        std::cout << "unique is nullptr" << std::endl;
    }
    return 0;
}
