#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

template <typename T>
void bubbleSort(vector<T>& vec) {
    size_t len = vec.size();
    for (size_t i = 0; i < len - 1; ++i) {
        bool isSwap = false;
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                isSwap = true;
            }
        }
        if (false == isSwap) {
            break;
        }
    }
}

template <typename T>
void printVector(const vector<T>& vec) {
    for (auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<double> nums{2.3, 10.7, -30.5, 78, 23, -9.9, -23, 67};
    printVector(nums);
    bubbleSort(nums);
    printVector(nums);
    return 0;
}

