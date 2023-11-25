#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;
  vector<int> v1{2, 5};
  vector<int> v2{0};
  vector<int> v3;
  v3.resize(v1.size() + v2.size());
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
  for (auto num : v3) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}