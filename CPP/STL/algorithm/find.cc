#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> nums{2, 34};
  auto it = find(nums.rbegin(), nums.rend(), 34);
  vector<int>::reverse_iterator it2 = find(nums.rbegin(), nums.rend(), 25);
  if (it == nums.rend()) {
    cout << "not found" << endl;
  } else {
    cout << "found" << endl;
  }

  if (it2 == nums.rend()) {
    cout << "not found again" << endl;
  }

  auto res = find_if(
      nums.begin(), nums.end(), [](int val) -> auto{ return val > 0; });
  if (res != nums.end()) {
    cout << "yes, some number > 0" << endl;;
  }
  return 0;
}