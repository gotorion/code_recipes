#include <iostream>
#include <algorithm>
#include <vector>
using std::lower_bound;
using std::upper_bound;
using std::vector;
int main()
{
    vector<double> datas{1.23, 7.4, 8.99, 9.10, 200, 234.45};
    auto it = upper_bound(datas.begin(), datas.end(), 200);
    std::cout << "it = " << *it << std::endl;
    return 0;
}

