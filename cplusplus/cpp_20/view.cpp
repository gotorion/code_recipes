#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

void test_0() {
  std::vector v{1, 2, 3, 4};
  auto view = std::views::drop(v, 0);
  for (auto elem : view) {
    std::cout << elem << std::endl;
  }
}

int main() {
  test_0();
}