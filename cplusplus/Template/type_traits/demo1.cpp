#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
auto func(T t) {
  if constexpr (std::is_same_v<decltype(t), int>) {
    return t + 1;
  }
  return t.substr(1);
}

void test_00() {
  int x = 10;
  if (std::is_same_v<decltype(x), int>) {
    std::cout << "is int\n";
  }
  int const& y = 20;
  if (std::is_same_v<decltype(y), int const&>) {
    std::cout << "is int const &\n";
  }
  if (std::is_same_v<int, std::decay_t<decltype(y)>>) {
    std::cout << "is int now\n";
  }
}

int main() {
  test_00();
  return 0;
}