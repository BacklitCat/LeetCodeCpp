// 二分搜索全攻略 https://zhuanlan.zhihu.com/p/466419249
#include<vector>

using namespace std;

// binarySearch 求非降序范围[l, r)内第一个value的值的位置，找不到返回-1
int binarySearch(vector<int> &nums, int target) {
    int left = 0, right = nums.size(), mid; // 左闭右开
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) { // 如果不存在target，则走不到这里
            return mid;
        } else if (nums[mid] > target) {
            right = mid;
            continue;
        } else if (nums[mid] < target) {
            left = mid + 1;
            continue;
        }
    }
    return -1;
}


// binarySearchLowerBound 求非降序范围[l, r)内第一个不小于value的值的位置
int binarySearchLowerBound(vector<int> &nums, int target) {
    int left = 0, right = nums.size(), mid; // 左闭右开
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) { // 如果不存在target，则走不到这里
            return mid;
        } else if (nums[mid] > target) {
            right = mid;
            continue;
        } else if (nums[mid] < target) {
            left = mid + 1;
            continue;
        }
    }
    return left;
}

