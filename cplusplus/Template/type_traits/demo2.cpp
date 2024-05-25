#include <string>
#include <type_traits>

template <typename F>
requires(std::is_floating_point_v<std::invoke_result_t<F>>) auto invoke(F f) {
  f();
  printf("Do nothing\n");
}

template <typename F>
auto invoke(F f) {
  printf("Start\n");
  //   if constexpr (std::is_same_v<decltype(f()), void>) {
  //   if constexpr (std::is_void_v<decltype(f())>) {
  if constexpr (std::is_void_v<std::invoke_result_t<F>>) {
    printf("End\n");
    return;
  } else {
    auto ret = f();
    printf("End\n");
    return ret;
  }
}

int main() {
  invoke([]() -> void { return; });
  invoke([]() -> int { return 1; });
  invoke([]() -> float { return 2.0; });
  return 0;
}