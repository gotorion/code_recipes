#include <cstddef>
#include <iostream>
template <typename T, unsigned N>
std::size_t len(T (&)[N]) {
  std::cout << "N version" << std::endl;
  return N;
}

template <typename T>
typename T::size_type len(T const& t) {
  std::cout << "Size version" << std::endl;
  return t.size();
}

inline std::size_t len(...) {
  return 0;
}