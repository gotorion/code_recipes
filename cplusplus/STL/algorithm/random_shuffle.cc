#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> nums;
  for (int i = 0; i < 100; ++i) {
    nums.push_back(i);
  }
  random_shuffle(nums.begin(), nums.end());

  for (auto x : nums) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}