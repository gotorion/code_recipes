#include <cassert>
#include <deque>
#include <string>
#include "stack1.hpp"

template <>  // 特化
class Stack<std::string> {
 private:
  std::deque<std::string> elems_;

 public:
};