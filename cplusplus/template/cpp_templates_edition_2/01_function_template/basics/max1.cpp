#include "max1.hpp"
#include <__format/format_functions.h>
#include <iostream>
int main() {
  int a = 10, b = 29;
  std::cout << std::format("{}", ::max(a, b)) << std::endl;

  std::cout << std::format("{}", ::max<double>(a, b)) << std::endl;
}