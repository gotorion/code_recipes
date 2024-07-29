#include "foreachinvoke.hpp"
#include <iostream>
#include <vector>

class MyClass {
 public:
  void memfunc(int i) const {
    std::cout << "MyClass::memfunc() called for : " << i << "\n";
  }
};
int main() {

  std::vector<int> nums{1, 2, 3};
  foreach (nums.begin(), nums.end(), &MyClass::memfunc, MyClass{})
    ;
}