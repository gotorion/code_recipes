#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

void print(int val) {
    cout << val << " ";
}

int main() {
    vector<int> nums{1, 2, 4, 56};
    for_each(nums.begin(), nums.end(), [&](int val)->void {
        cout << val << " ";
    });
    cout << endl;
    return 0;
}