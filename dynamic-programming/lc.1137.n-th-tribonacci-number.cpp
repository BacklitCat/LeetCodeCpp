// https://leetcode.cn/problems/n-th-tribonacci-number

int ans[38]={0};

class Solution {
public:
    int tribonacci(int n) {
        ans[1]=1; ans[2]=1;
        if(n > 2) {
            for(int i=3; i<=n; i++){
                ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
            }
        }
        return ans[n];
    }
};