#include <any>
#include <format>
#include <iostream>

int main() {
  std::any a = 1;
  std::cout << std::format("{}, {}", a.type().name(), std::any_cast<int>(a))
            << std::endl;

  // bad cast
  try {
    a = 1;
    std::cout << std::any_cast<float>(a) << std::endl;
  } catch (const std::bad_any_cast& e) {
    std::cerr << e.what() << '\n';
  }
  if (a.has_value()) {
    std::cout << std::format("{}", "Has value") << std::endl;
  }
  a.reset();
  if (!a.has_value()) {
    std::cout << "No value" << std::endl;
  }
  a = 3;
  int* ptr = std::any_cast<int>(&a);
  std::cout << *ptr << std::endl;

  return 0;
}