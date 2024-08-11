#include <cassert>
#include <iostream>
#include <vector>

template <typename T = int>
class Stack {
 private:
  std::vector<T> elems_;

 public:
  Stack(Stack const&);  // no need for type T

  void push(T const& elem);
  void pop();
  T const& top() const;
  bool empty() const { return elems_.empty(); }
  void printOn(std::ostream& os) {
    for (auto elem : elems_) {
      os << elem << " ";
    }
    os << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& strm, Stack<T> const& s) {
    s.printOn(strm);
    return strm;
  }
};

template <typename T>
void Stack<T>::push(const T& elem) {
  elems_.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
  elems_.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
  assert(!elems_.empty());
  return elems_.back();
}
