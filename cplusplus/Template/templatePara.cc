#include <iostream>
using namespace std;

template <typename T = int, size_t kMin = 10>
T multiply(T x, T y) {
  return x * y * kMin;
}

int main() {
  int ia = 10, ib = 20;
  cout << multiply<int, 100>(ia, ib) << endl;
  cout << multiply(ia, ib) << endl;
  double da = 3.3;
  cout << multiply<double>(da, da) << endl;
}