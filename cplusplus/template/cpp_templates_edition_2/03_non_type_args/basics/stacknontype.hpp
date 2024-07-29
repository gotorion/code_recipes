#include <array>
#include <cassert>
#include <cstddef>

template <typename T, std::size_t MaxSize = 20>
class Stack {
 private:
  std::array<T, MaxSize> elems_;
  std::size_t numElems_;

 public:
  Stack();
  void push(T const& elem);
  void pop();
  T const& top() const;
  bool empty() const;
  std::size_t size() const;
};