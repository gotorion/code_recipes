#include <iostream>
#include <type_traits>

template <typename T>
void gench(T t) {

  if constexpr (requires { t.dismatch(); }) {
    t.dismatch();
  } else if constexpr (requires { t.rebel(std::declval<int>); }) {
    t.rebel(10);
  } else {
    t.rebel();
  }
}

struct Teacher {
  void rebel() { std::cout << "rebel" << std::endl; }
  void rebel(int x) { std::cout << "rebel " << x << std::endl; }
};

struct Student {
  void dismatch() { std::cout << "dismatch" << std::endl; }
};

int main() {
  Teacher t;
  Student s;
  gench(t);
  gench(s);
}