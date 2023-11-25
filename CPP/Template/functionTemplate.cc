#include <iostream>
#include <string>
using namespace std;

template <typename T>
T add(T x, T y) {
  cout << "T add(T, T)" << endl;
  return x + y;
}

template <typename T1, typename T2>
T1 add(T1 x, T2 y) {
  cout << "T1 add(T1, T2)" << endl;
  return x + y;
}

template <typename T>
T add(T x, T y, T z) {
  cout << "T add(T, T, T)" << endl;
  return x + y + z;
}
// 模板全特化
template <>
const char *add<const char *>(const char *px, const char *py) {
  cout << "const char * add()" << endl;
  // do something
  return px;
}

template <typename T1, typename T2>
class Test {};

template <>
class Test<int, int> {
 public:
  Test(int a, int b) { cout << "模板全特化" << endl; }
};

template <typename T>
class Test<int, T> {
 public:
  Test(int a, T b) : _a(a), _b(b) { cout << "模板偏特化" << endl; }

 private:
  int _a;
  T _b;
};

int main() {
  int ia = 3, ib = 4, ic = 5;
  char ca = 'a', cb = 1;
  double da = 3.3, db = 4.4;
  string s1 = "Hello", s2 = "world";
  const char *pstr1 = "Hello";
  const char *pstr2 = "world";
  cout << add(ia, ib) << endl;
  cout << add<char>(ca, cb) << endl;
  cout << add(da, db) << endl;
  cout << add(s1, s2) << endl;
  cout << add(ia, ib, ic) << endl;

  cout << add(pstr1, pstr2) << endl;

  // 偏特化
  Test<int, int> t1(1, 1);
  Test<int, char *> t2(1, "hello");
}