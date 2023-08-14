#include<vector>
#include <algorithm>

using namespace std;

// 455 Easy https://leetcode.cn/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end()); sort(s.begin(),s.end());
        int count=0;
        // 归并遍历
        for (int i=0,j=0; i<g.size()&&j<s.size();){
            if (s[j]>=g[i]){ // 吃
                i++;j++;count++;
            } else{ // 不够吃
                j++; // 换大饼干
            }
        }
        return count;
    }
};