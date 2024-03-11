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

void test_lexical_repo() { LexicalRepo repo{"Hello", "world"}; }

int main() {
  test_lexical_repo();
  return 0;
}
