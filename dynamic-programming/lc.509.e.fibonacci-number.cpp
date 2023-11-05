// https://leetcode.cn/problems/fibonacci-number/

int ans[31]={0};  // 0 <= n <= 30

class Solution {
public:
    int fib(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        ans[1]=1;
        if (ans[n]!=0) return ans[n];
        for (int i=2; i<=n; i++){
            if (ans[i]!=0) continue;
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};