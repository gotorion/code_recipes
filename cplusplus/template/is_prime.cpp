#include <iostream>

template <unsigned p, unsigned d>
struct DoIsPrime {
  static constexpr bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};

template <unsigned p>
struct DoIsPrime<p, 2> {
  static constexpr bool value = (p % 2 != 0);
};

template <unsigned p>
struct IsPrime {
  static constexpr bool value = DoIsPrime<p, p / 2>::value;
};

int main() {
  if (IsPrime<10>::value) {
    std::cout << "IsPrime" << std::endl;
  }
  if (IsPrime<7>::value) {
    std::cout << "7IsPrime" << std::endl;
  }
  return 0;
}