#include <vector>
#include <cstdlib>

using namespace std;

// 一次分治，闭区间，范围[i,j]，返回一个确定的位置 i
int partition(vector<int> &nums, int l, int r) {
    int rd = rand() % (r - l + 1) + l;
    swap(nums[l], nums[rd]);
    int pivot = l, i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] >= nums[pivot]) {
            j--;
        }
        while (i < j && nums[i] <= nums[pivot]) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[pivot]);// i=j
    return i;
}

void quickSort(vector<int> &nums, int l, int r) {
    if (l > r) { return; }
    int i = partition(nums, l, r);
    quickSort(nums, 0, i - 1);
    quickSort(nums, i + 1, r);
}

void QuickSort(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
}