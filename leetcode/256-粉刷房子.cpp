#include <vector>
#include <algorithm> //sort,min_element,max_element

using namespace std;

// M 会员题 动态规划
// https://leetcode.cn/problems/paint-house/?envType=study-plan-v2&envId=premium-algo-100

int min_row(const vector<int> &row) {
    return *min_element(row.begin(), row.end());
}

class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        vector<int> dp(3,0); // 涂到当前房子的总最小花费
        vector<int> temp(3,0); // 不能直接用dp 会使用临时计算结果
        for (auto const & cost: costs) {
            temp[0] = cost[0] +  min(dp[1],dp[2]);
            temp[1] = cost[1] +  min(dp[0],dp[2]);
            temp[2] = cost[2] +  min(dp[0],dp[1]);
            dp = temp;
        }
        return min_row(dp);
    }
};

// 拓展：如果是k个颜色，如何在o(nk)时间内解决
// 答：每次记录最小值和次小值