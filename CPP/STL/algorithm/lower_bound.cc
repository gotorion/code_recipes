#include <iostream>
#include <algorithm>
#include <vector>
using std::lower_bound;
using std::vector;
int main()
{
    vector<double> datas{1.23, 7.4, 8.99, 9.10, 200, 234.45};
    auto it = lower_bound(datas.begin(), datas.end(), 9.0);
    auto it2 = lower_bound(datas.begin(), datas.end(), 200);
    std::cout << "it = " << *it << std::endl;
    std::cout << "it2 = " << *it2 << std::endl;
    return 0;
}

