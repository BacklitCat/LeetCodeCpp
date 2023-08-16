#include <vector>
#include <string>

using namespace std;

// Mid 322 https://leetcode.cn/problems/coin-change
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int dp[amount+1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        // for(auto num:dp){
        //     cout << num << " ";
        // }cout<<endl;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    // cout <<"log:i="<<i<<"j="<<j<<"coin="<<coins[j]<<"dp[i]="<<dp[i]<<"dp[i-coins[j]]+1="<<dp[i - coins[j]]+1;
                    dp[i] = min(dp[i], dp[i - coins[j]]+1);
                    // cout<<", dp[i]="<<dp[i]<<endl;
                }
            }
        }
        // for(auto num:dp){
        //     cout << num << " ";
        // }cout<<endl;
        if(dp[amount]>=0x3f3f3f3f){return -1;}
        return dp[amount];
    }
};