#include <iostream>

template <int M, int K, int S>
struct MksUnit {
  enum { metre = M, kilogram = K, second = S };
};

template <typename MksUnit>
class Value {
 public:
  explicit Value(const long double magnitude) : magnitude_(magnitude) {}
  constexpr long double getMagnitude() const noexcept { return magnitude_; }

 private:
  long double magnitude_{0.0};
};
using Momentum = Value<MksUnit<1, 1, -1>>;
class SpaceCraftControl {
 public:
  void applyMomentumToSpaceCraftBody(const Momentum& impulseValue) {
    std::cout << "no implement" << std::endl;
  }
};

int main() { return 0; }