#include <iostream>
constexpr int const_value = 10;

void test_constexpt_value() {
  // const_value = 20; // error
}

constexpr int multiply(const int num_1, const int num_2) {
  return num_1 * num_2;
}

int main() { return 0; }