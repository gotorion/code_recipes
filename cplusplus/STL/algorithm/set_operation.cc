#include <algorithm>
#include <iostream>
#include <set>
#include <iterator>
std::set<int> nums_1{2, 3, 4, 5, 6};
std::set<int> nums_2{2, 3, 4, 5};
int main() {
    std::set<int> diff;
    std::vector<int> res;
    std::set_difference(nums_1.begin(), nums_1.end(),
                        nums_2.begin(), nums_2.end(),
                        std::back_inserter(res));

    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}