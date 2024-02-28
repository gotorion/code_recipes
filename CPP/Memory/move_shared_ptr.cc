#include <memory>
#include <functional>
#include <iostream>
int main() {
    std::shared_ptr<int> before = std::make_shared<int>(10);
    std::cout << "before = " << *before << std::endl;
    std::shared_ptr<int> temp = before;
    std::cout << "now before count = " << before.use_count() << std::endl;
    std::cout << "temp = " << *temp << std::endl;
    std::shared_ptr<int> moveTo = std::move(before);
    std::cout << "now temp = " << *temp << std::endl;
    std::cout << "now temp count = " << temp.use_count() << std::endl;
    return 0;
}