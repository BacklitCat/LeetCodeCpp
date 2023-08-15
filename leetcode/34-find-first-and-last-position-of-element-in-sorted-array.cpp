#include <vector>
#include <iostream> // stringstream
#include <algorithm> //sort
#include <string> //stoi,memset
#include <unordered_map>
#include <unordered_set>
#include <cstdlib> // rand
#include <queue> // queue,priority_queue

using namespace std;

class Solution {
public:
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

    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0) { return {-1, -1}; }
        int low = -1, high = -1;
        low = binarySearchLowerBound(nums, target);
        if (low >= nums.size() || nums[low] != target) { return {-1, -1}; }
        high = binarySearchHigherBound(nums, target);
        return {low, high};
    }
};

int main() {
    Solution s;
    vector<int> nums{2, 2};
    cout << s.binarySearchLowerBound(nums, 2) << endl; // 0
    cout << s.binarySearchHigherBound(nums, 2) << endl; //1

    nums = {1, 2, 4, 5};
    cout << s.binarySearchLowerBound(nums, 3) << endl; //2
    cout << s.binarySearchHigherBound(nums, 3) << endl; //1
}