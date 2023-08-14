#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int searchMax(vector<int> &nums) {
        int left = 0, right = nums.size(), mid; // 左闭右开
        while (left < right) {
            // cout<<"a "<<left<<" "<<right<<endl;
            mid = left + (right - left) / 2;
            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) { return mid; }
            if (nums[mid] >= nums[0]) {
                // cout<<"b "<<mid<<" "<<left<<" "<<right<<endl;
                left = mid + 1;
            } else if (nums[mid] < nums[0]) {
                right = mid;
            }
        }
        return mid; // left==right==mid
    }

    int search(vector<int> &nums, int target) {
        int max_loc = searchMax(nums);
        // cout<<max_loc;
        // 剪枝
        if (target == nums[max_loc]) { return max_loc; }
        if (target == nums[0]) { return 0; }
        if (target == nums.back()) { return nums.size() - 1; }
        if (target > nums[max_loc] ||
            ((max_loc + 1 < nums.size()) && (target < nums[max_loc + 1])) ||
            ((max_loc == 0) && (target > nums[0]))) {
            return -1;
        }
        // 搜索
        int left, right, mid; // 左闭右开
        if (target > nums[0]) {//  左边大区
            left = 0;
            right = max_loc;
        } else {
            left = max_loc + 1;
            right = nums.size();
        }
        // cout<<"c "<<left<<" "<<right<<endl;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};