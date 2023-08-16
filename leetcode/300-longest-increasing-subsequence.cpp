#include <vector>
#include <iostream> // stringstream
#include <algorithm> //sort
#include <string> //stoi,memset(mac)
#include <unordered_map>
#include <unordered_set>
#include <cstdlib> // rand
#include <queue> // queue,priority_queue
#include <cstring> //memset(windows)

using namespace std;

// Mid 300 https://leetcode.cn/problemset/all/
// dp n^2 贪心+二分=nlogn （d[i]表示i长度的子序列的末尾元素的最小值）
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int dp[nums.size() + 1];
        int res = 1;
        memset(dp, -1, sizeof dp);
        dp[0] = 0;

//        for (auto num: dp) {
//            cout << num << " ";
//        }
//        cout << endl;

        // DP时一定小心下标对齐 i,j 代表从1计数的第i个字符
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = i - 1; j >= 1; j--) {
                // 向前倒找，寻找比其小，且是最大的最长子序列
                if (nums[j-1] < nums[i-1]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            if (dp[i] == -1) { dp[i] = 1; }
            res = max(res, dp[i]);
        }

//        for (auto num: dp) {
//            cout << num << " ";
//        }
//        cout << endl;

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//    cout << s.lengthOfLIS(nums)<<endl; //4
//    nums = {0,1,0,3,2,3};
//    cout << s.lengthOfLIS(nums)<<endl;//4
//    nums = {7,7,7,7};
//    cout << s.lengthOfLIS(nums)<<endl;//1
    nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << s.lengthOfLIS(nums) << endl;//6
}