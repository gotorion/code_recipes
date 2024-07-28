#include "enum_reflect.h"
#include <iostream>
enum Color {
  RED = 1,
  BLUE = 2,
  GREEN = 3,
  YELLOW = 4,
};

namespace utils {
struct TestClass;
}

int main() {
  Color c = YELLOW;
  std::cout << my_enum::get_name_dynamic(c) << std::endl;
  std::cout << my_enum::enum_from_name<Color>("YELLOW") << std::endl;
}