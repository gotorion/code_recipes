#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Transform {
 public:
  int operator()(int v) { return v + 666; }
};

class Print {
 public:
  void operator()(int val) { cout << val << " "; }
};

int main() {
    vector<int> nums{7, 324, -4, 95, 72, 9};
    for_each(nums.begin(), nums.end(), [](int val)->void{
        cout << val << " ";
    });

    vector<int> anotherNums;
    anotherNums.resize(nums.size());
    transform(nums.begin(), nums.end(), anotherNums.begin(), Transform());
    for_each(anotherNums.begin(), anotherNums.end(), Print());
    
    cout << endl;
    return 0;
}