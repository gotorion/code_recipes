#include <iostream>
#include <string>
#include <type_traits>
using namespace std::string_literals;
using namespace std::literals;
int main() {
  auto s = "Hello"s;
  auto view = "Hello"sv;
  std::cout << s << std::endl;
  if (std::is_same_v<decltype(s), std::string>) {
    std::cout << "s is string" << std::endl;
  }
}