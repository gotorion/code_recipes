#include <iostream>
#include <string>
using namespace std;

template <typename T>
string get_type_name() {
  string s = __PRETTY_FUNCTION__;
  auto pos = s.find("T = ");

  auto start = pos += 4;
  auto end = s.find_first_of(";]", pos);
  return s.substr(start, end - start);
}

template <typename T, T N>
string get_int_name() {
  string s = __PRETTY_FUNCTION__;
  auto pos = s.find("N = ");

  auto start = pos += 4;
  auto end = s.find_first_of(";]", pos);
  return s.substr(start, end - start);
}

enum Color { RED = 1, GREEN, YELLOW };

template <int N>
struct int_constant {
  static constexpr int value = N;
};

template <int Beg, int End, typename F>
void static_for(F const& f) {
  if constexpr (Beg == End) {
    return;
  } else {
    f(int_constant<Beg>());
    static_for<Beg + 1, End>(f);
  }
}

template <typename T>
string get_int_name_dynamic(T n) {
  // 编译期for循环
  string ret;
  static_for<0, 256>([&](auto ic) {
    auto i = ic.value;
    if (n == (T)i) {
      ret = get_int_name<T, (T)i>();
    }
  });
  return ret;
  // 暴力方法
  /*   if (n == 1) {
    return get_int_name<T, (T)1>();
  } else if (n == 2) {
    return get_int_name<T, (T)2>();
  } else {
    return get_int_name<T, (T)3>();
  } */
}
int main() {
  constexpr Color color = RED;
  cout << get_int_name<Color, color>() << endl;  // color必须是静态编译器常量

  Color c = RED;
  cout << get_int_name_dynamic(c) << endl;  // 通过这种方式将运行时转换为常量
}
