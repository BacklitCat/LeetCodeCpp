#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3) {
            return {};
        }
        // 排序+双指针，排序，固定i；j，k从两边向中间
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                // 去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                while (j < k && k + 1 < nums.size() && nums[k] == nums[k + 1]) {
                    k--;
                }
                // 如果此时指针相遇，则退出
                if (j == k) { break; }
                // 判断
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
                // 移动
                if (nums[j] + nums[k] < -nums[i]) {
                    j++; // 需要变大
                } else {
                    k--; // 需要变小
                }
            }
        }
        return res;
    }
};