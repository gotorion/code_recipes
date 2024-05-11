#include <iostream>
#include <vector>
using WordList = std::vector<std::string>;

class LexicalRepo {
 public:
  explicit LexicalRepo(const std::initializer_list<const char*>& words) {
    wordList_.insert(std::begin(wordList_), std::begin(words), std::end(words));
  }

 private:
  WordList wordList_;
};

void test_lexical_repo() {
  LexicalRepo repo{"Hello", "world"};
}

struct Pig {
  // 这里是没有写构造函数的
  std::string name_;
  int age_;
};

class Person {
 public:
  Person(std::initializer_list<std::string> val) noexcept {
    // note that initializer_list usuaual not use for this condition
    auto iter = std::begin(val);
    name_ = *iter;
    iter++;
    country_ = *iter;
    iter++;
    address_ = *iter;
  }
  void print() const {
    std::cout << "Name : " << name_ << std::endl;
    std::cout << "Country : " << country_ << std::endl;
    std::cout << "Address : " << address_ << std::endl;
  }

 private:
  std::string name_;
  std::string country_;
  std::string address_;
};

int main() {
  // Pig redPig{"Petty", 18}; // C++11自动生成列表初始化函数
  // test_lexical_repo();
  //
  Person me{"John", "US", "SaltLake City"};
  me.print();
  return 0;
}
