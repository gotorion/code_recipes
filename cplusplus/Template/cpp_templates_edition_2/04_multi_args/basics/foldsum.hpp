template <typename... T>
auto foldSum(T... s) {
  return (... + s);
}