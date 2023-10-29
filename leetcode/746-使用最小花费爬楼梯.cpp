#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划
    // 到达i位置的最小花费，仅仅取决于 i-2 和 i-1 位置
    // 计算到达每一个位置的最小花费
    int minCostClimbingStairs(vector<int> &cost) {
        // 如果台阶只有1个，没有花费
        if (cost.size() <= 1) return 0;
        // 如果台阶只有2个，则花费为最小的那个台阶
        if (cost.size() == 2) return min(cost[0], cost[1]);
        // 从第3个元素开始计算(从1计数)，虚拟出开始和结束的台阶
        int loc = 2, n = cost.size();
        long long dp1 = 0, dp2 = 0, dp3;

        for (; loc <= n; loc++) {
            dp3 = min(dp1 + cost[loc - 2], dp2 + cost[loc - 1]);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp2;
    }
};


int main() {
    Solution ss;
    vector<int> nums1 = {10, 15, 20};
    vector<int> nums2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << ss.minCostClimbingStairs(nums1) << endl; // 15
    cout << ss.minCostClimbingStairs(nums2) << endl; // 6
    return 0;
}