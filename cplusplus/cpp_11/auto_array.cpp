#include <iostream>
#include <vector>
void func(auto num) { std::cout << num << std::endl; }

void test_auto() {
  std::vector<int> arr{1, 2, 3};
  auto iter = std::begin(arr);
  std::cout << *iter << std::endl;
}

int main() {
  int arr[3] = {1, 2, 3};
  auto b = arr;
  std::cout << typeid(b).name() << std::endl;

  auto &c = arr;
  std::cout << typeid(c).name() << std::endl;

  func(10);

  test_auto();
  return 0;
}