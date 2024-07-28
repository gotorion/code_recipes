#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>

#if defined(__MSC_VER)
std::string s(__FUNCSIG__);
#error "unsupported compiler"
#elif defined(__GNUC__) || defined(__clang__)
namespace my_enum {
#define LOG(x) (std::cout << __PRETTY_FUNCTION << std::endl)

namespace details {
template <typename T>
std::string get_type_name() {
  std::string s(__PRETTY_FUNCTION__);
  auto pos = s.find("T = ");
  pos += 4;
  auto end_pos = s.find_first_of(";]", pos);
  return s.substr(pos, end_pos - pos);
}

template <int N>
std::string get_int_name() {
  std::string s(__PRETTY_FUNCTION__);
  auto pos = s.find("N = ");
  if (pos == s.npos) {
    return std::to_string((int)N);
  }
  pos += 4;
  auto end_pos = s.find_first_of(";]", pos);
  return s.substr(pos, end_pos - pos);
}

template <typename T, T N>
std::string get_name() {
  std::string s(__PRETTY_FUNCTION__);
  auto pos = s.find("N = ");
  pos += 4;
  auto end_pos = s.find_first_of(";]", pos);
  return s.substr(pos, end_pos - pos);
}

template <int N>
struct integral_constant {
  static constexpr int value = N;
};

template <int Begin, int End, typename F>
void static_for(F const& f) {
  if constexpr (Begin == End) {
    return;
  } else {
    f(integral_constant<Begin>());
    static_for<Begin + 1, End>(f);
  }
}
}  // namespace details

template <typename T>
std::string get_name_dynamic(T n) {

  std::string ret;
  details::static_for<0, 256>([&](auto ic) {
    constexpr auto i = ic.value;
    if (n == (T)i) {
      ret = details::get_name<T, (T)i>();
    }
  });
  return ret;
}

template <typename T, int Begin = 0, int End = 256>
T enum_from_name(std::string const& s) {
  for (int i = Begin; i < End; ++i) {
    if (s == get_name_dynamic((T)i)) {
      return (T)i;
    }
  }
  throw std::runtime_error("Not found");
}
}  // namespace my_enum
#endif