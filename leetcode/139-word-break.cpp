#include <vector>
#include <algorithm> //sort
#include <string> //stoi,memset
#include <unordered_map>
#include <unordered_set>

using namespace std;


// Mid 139 https://leetcode.cn/problems/word-break
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 动态规划，定义d[i]为[0,i)的字符串是否能被拼接
        bool dp[s.size() + 1];
        fill_n(dp,s.size() + 1, false);
        unordered_set<string> hash_set;

        for(auto &word : wordDict){
            hash_set.emplace(word);
        }

        dp[0] = true;

        for(int i=1;i<=s.size();i++){ // 更新dp[i],遍历到第i个字符
            // 新增一个字符，但是需要i内所有的都尝试分割一次，才知道有没有以当前新字符结尾的分割方式, o(n^2)
            // j是分割点
            for(int j=0;j<i;j++){
                if(dp[j] && hash_set.find(s.substr(j, i - j)) != hash_set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
//        for (auto num : dp){
//            cout << num << " ";
//        }
        return dp[s.size()];
    }
};