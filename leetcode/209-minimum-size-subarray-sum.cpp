#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        // 毛毛虫双指针 [i,j) 数组内的和不够target，j向右探索，否则i向右
        int i = 0, j = 0, sum = 0, min_len = 0x7fffffff;
        while (j < nums.size()) {
            if (sum + nums[j] >= target) {
                min_len = min(min_len, j - i + 1);
                sum = sum -nums[i];
                i++;
            } else if (sum + nums[j] < target) {
                sum += nums[j];
                j++;
                continue;
            }
        }
        if (j == nums.size() && min_len>= 0x7fffffff) { return 0; }
        return min_len;
    }
};