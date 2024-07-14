#include <iostream>
void print() {}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
  std::cout << "Current size of args: " << sizeof...(args) << std::endl;
  std::cout << firstArg << "\n";
  print(args...);
}