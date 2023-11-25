#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums{8, 2, 34, -1, 84};
  auto it = adjacent_find(nums.begin(), nums.end());
  if (it == nums.end()) {
    cout << "not found" << endl;
  }
  nums.push_back(84);
  it = adjacent_find(nums.begin(), nums.end());
  cout << *it << endl;
  it++;
  if (it == nums.end()) {
    cout << "second one" << endl;
  } else {
    cout << "first one" << endl;
  }
  return 0;
}