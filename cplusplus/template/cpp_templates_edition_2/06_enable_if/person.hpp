#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

template <typename T>
using EnableIfString = std::enable_if_t<std::is_convertible_v<T, std::string>>;
class Person {
 private:
  std::string name_;

 public:
  template <typename STR, typename = EnableIfString<STR>>
  explicit Person(STR&& n) : name_(std::forward<STR>(n)) {
    std::cout << "TMPL_CONSTR for'" << name_ << "'\n";
  }

  Person(Person const& p) : name_(p.name_) {
    std::cout << "COPY PERSON CONSTRUCT" << std::endl;
  }

  Person(Person&& p) : name_(std::move(p.name_)) {
    std::cout << "MOVE PERSON CONSTRUCT" << std::endl;
  }
};