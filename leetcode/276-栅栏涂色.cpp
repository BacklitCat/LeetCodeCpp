//#include <vector>

using namespace std;

// M 会员题 动态规划
// https://leetcode.cn/problems/paint-fence/?envType=study-plan-v2&envId=premium-algo-100

class Solution {
public:
    int numWays(int n, int k) {
        // 快速返回前2次
        if (n == 1) {
            return k;
        } else if (n == 2) {
            return k * k;
        }
        // 从第3次开始算 [dp1 dp2 dp3]
        long long dp1 = k, dp2 = k * k, dp3 = 0, i = 3;
        while (i <= n) {
            // 与之前不同 dp2 * (k-1)
            // 相同需要这样思考：什么时候能相同？前一元素和前前元素不能相同，再*1 即 dp1*(k-1)*1
            dp3 = dp2 * (k - 1) + dp1 * (k - 1) * 1;
            dp1 = dp2;
            dp2 = dp3;
            i++;
        }
        return dp3;
    }
};