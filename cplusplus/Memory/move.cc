#include <iostream>
#include <memory>

std::unique_ptr<int> move_and_give_back(std::unique_ptr<int> num) {
  std::cout << "num in func = " << *num << std::endl;
  return std::move(num);
}

int main() {
  std::unique_ptr<int> num = std::make_unique<int>(10);
  std::cout << "num = " << *num << std::endl;

  std::unique_ptr<int> ret = move_and_give_back(std::move(num));
  std::cout << "ret = " << *ret << std::endl;

  //   std::cout << "num = " << *num << std::endl; // error
  return 0;
}