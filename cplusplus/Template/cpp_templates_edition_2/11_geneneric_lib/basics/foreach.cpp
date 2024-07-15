#include "foreach.hpp"
#include <iostream>
#include <vector>

void func(int i) {
  std::cout << "func() called for : " << i << "\n";
}

class FuncObj {
 public:
  void operator()(int i) const {

    std::cout << "FuncObj::op() called for : " << i << "\n";
  }
};

int main() {
  std::vector primes{2, 3, 5, 7};
  foreach (primes.begin(), primes.end(), func)
    ;

  foreach (primes.begin(), primes.end(), &func)
    ;
  foreach (primes.begin(), primes.end(), FuncObj{})
    ;


}