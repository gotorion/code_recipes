#include "person.hpp"
int main() {
  std::string s = "name";
  Person p1(s);
  Person p2("Name");
  Person p3(p1);
  Person p4(std::move(Person("temp")));
}