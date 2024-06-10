#include <iostream>
int main() {
  char16_t uc1 = u'a';
  char32_t uc2 = U'a';
  std::cout << sizeof(uc1) << " " << sizeof(uc2) << std::endl;
}