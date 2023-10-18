#include <iostream>
#include <ctime>
#include <vector>
using std::vector, std::cout, std::endl;

void quickSort(vector<int>& nums, int left, int right) {
  if (left >= right) {
    return;
  }
		       
  int rdmIdx = left + rand() % (right - left + 1);
  int pivot = nums[rdmIdx];
  std::swap(nums[rdmIdx], nums[left]);

  int lBorder = left, rBorder = right;
  while (lBorder < rBorder) {
    while (lBorder < rBorder && nums[rBorder] >= pivot) {
      --rBorder;
    }
    nums[lBorder] = nums[rBorder];
    while (lBorder < rBorder && nums[lBorder] <= pivot) {
      ++lBorder;
    }
    nums[rBorder] = nums[lBorder];
  }
  nums[lBorder] = pivot;
  quickSort(nums, left, lBorder - 1);
  quickSort(nums, lBorder + 1, right);
}

void printNums(const vector<int>& nums) {
  for (auto& elem : nums) {
    cout << elem << " ";
  }
  cout << endl;
}

int main() {
  vector<int> unOrdered{2, 93, 4, -1, -23, 8, -235, -84};
  printNums(unOrdered);
  ::srand(time(nullptr));
  quickSort(unOrdered, 0, unOrdered.size() - 1);
  printNums(unOrdered);

  return 0;
}
