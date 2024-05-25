#include <chrono>
#include <thread>
using namespace std::literals::chrono_literals;
int main() {
  auto time = 3h;
  std::this_thread::sleep_for(3s);
  return 0;
}