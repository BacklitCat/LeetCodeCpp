// 二分搜索全攻略 https://zhuanlan.zhihu.com/p/466419249
#include<vector>

using namespace std;

// binarySearch 求非降序范围[l, r)内value的左边界
int binarySearchLowerBound(vector<int> &nums, int target) {
    int low = 0, high = nums.size(), mid = -1; // 左闭右开
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target) { // 收缩右边界
            high = mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid;
        }
    }
    return low;
}


// binarySearchLowerBound 求非降序范围[l, r)内value的右边界
int binarySearchHigherBound(vector<int> &nums, int target) {
    int low = 0, high = nums.size(), mid = -1; // 左开右闭
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target) { // 收缩左边界
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid;
        }
    }
    return low - 1;
}

