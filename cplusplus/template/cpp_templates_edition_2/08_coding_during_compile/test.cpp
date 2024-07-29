#include <iostream>
#include <vector>
#include "isprime.hpp"
#include "sfinae.hpp"

void test_sfinae() {
  len(std::vector<int>(10, 10));
  int arr[10];
  len(arr);

  int* p = nullptr;
  //   len(p); // error
}

int main() {
  if (IsPrime<7>::value) {
    std::cout << "is prime" << std::endl;
  }
  test_sfinae();
  return 0;
}