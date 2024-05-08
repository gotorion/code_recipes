#include <iostream>
#include <vector>
using WordList = std::vector<std::string>;

class LexicalRepo
{
public:
  explicit LexicalRepo(const std::initializer_list<const char *> &words)
  {
    wordList_.insert(std::begin(wordList_), std::begin(words), std::end(words));
  }

private:
  WordList wordList_;
};

void test_lexical_repo() { LexicalRepo repo{"Hello", "world"}; }

struct Pig
{
  // 这里是没有写构造函数的
  std::string name_;
  int age_;
};

int main()
{
  Pig redPig{"Petty", 18}; // C++11自动生成列表初始化函数
  test_lexical_repo();
  return 0;
}
