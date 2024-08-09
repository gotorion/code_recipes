#include <array>
#include <cstdio>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>
int main() {
  auto x = std::vector{1, 2, 3, 4};
  auto y = std::list<std::string>{"α", "β", "γ", "δ", "ε"};
  auto z = std::array{'A', 'B', 'C', 'D', 'E', 'F'};
  for (std::tuple<int&, std::string&, char&> elem : std::views::zip(x, y, z)) {
    std::cout << std::get<0>(elem) << ' ' << std::get<1>(elem) << ' '
              << std::get<2>(elem) << '\n';

    std::get<char&>(elem) += ('a' - 'A');  // modifies the element of z
  }
  printf("\n");
}