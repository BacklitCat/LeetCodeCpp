#include<string>
#include <unordered_map>

using namespace std;

// Mid 3 https://leetcode.cn/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) { return s.size(); }
        unordered_map<char, int> hashMap;
        int res = 1;
        hashMap[s[0]] = 0;
        for (int i = 0, j = 1; j < s.size();) {
            // 寻找当前探索元素是否重复
            auto loc = hashMap.find(s[j]);
            // 如果不重复
            if (loc == hashMap.end() || loc->second == -1) {
                // 记录该元素位置
                hashMap[s[j]] = j;
                // 更新最大值
                res = max(res, j - i + 1);
                // 继续探索
                j++;
            } else { // 如果重复
                // 找到先前一个重复点，左指针指向重复点的下一点，之间的元素去掉记录
                while (i <= loc->second) {
                    hashMap[s[i]] = -1;
                    i++;
                }
            }
        }
        return res;
    }
};