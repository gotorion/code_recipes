template <int Value, typename T>
T addValue(T x) {
  return x + Value;
}

template <auto Value, typename T = decltype(Value)>
T foo() {}

template <typename T, T Val = T{}>
T bar() {}