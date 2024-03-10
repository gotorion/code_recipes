#include <iostream>
#include <utility>

template <class T, class U>
auto add(T t, U u) {
  return t + u;
}

template <class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args) {
  return fun(std::forward<Args>(args)...);
}

template <auto n>
auto f() -> std::pair<decltype(n), decltype(n)> {
  return {n, n};
}

int main() {
  auto a = 1 + 2;
  auto b = add(1, 1.2);
  static_assert(std::is_same_v<decltype(a), int>);
  static_assert(std::is_same_v<decltype(b), double>);

  auto c0 = a; // int
  decltype(auto) c1 = a;
  decltype(auto) c2 = (a); // c2 is reference

  auto [v, w] = f<0>();
  std::cout << "v = " << v << " and w = " << w << std::endl;

  auto d = {1, 2};
  auto n = {5};
  auto m{5};
}
