#include <future>
#include <iostream>
bool is_prime(int x) {
  for (int i = 0; i < x; ++i) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  std::future<bool> fut = std::async(is_prime, 8234234);
  std::cout << "please wait";
  std::chrono::microseconds span(100);
  while (fut.wait_for(span) != std::future_status::ready) {
    std::cout << ".";
  }
  std::cout << std::endl;

  bool ret = fut.get();
  std::cout << "final result:" << (ret ? "TRUE" : "FALSE") << std::endl;
  return 0;
}