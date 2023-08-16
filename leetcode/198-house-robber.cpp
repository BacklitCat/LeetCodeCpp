#include <vector>
#include <iostream> // stringstream

using namespace std;

// Mid 198 https://leetcode.cn/problems/house-robber/
// bad case [2,1,1,2]
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) { return nums[0]; }
        int dp[nums.size()][2];
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for (int i=1;i<nums.size();i++){
            dp[i][0] = nums[i] + dp[i-1][1];
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]); // 这里曾经错过
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};