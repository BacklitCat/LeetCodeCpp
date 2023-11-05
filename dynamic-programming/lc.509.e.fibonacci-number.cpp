#include <iostream>

// https://leetcode.cn/problems/fibonacci-number/

int ans[30]={0};  // 0 <= n <= 30

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) { ans[1]=1; return 1;}
    }
};