#include <string>
#include <iostream>

using namespace std;


// Mid 5 https://leetcode.cn/problems/longest-palindromic-substring
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) { return s; }
        // 中心扩散
        int i, l, r, count = 1;
        string res = s.substr(0, 1);
        // 单中心
        for (i = 1; i < s.size() - 1; i++) {
            for (l = i - 1, r = i + 1; l >= 0 && r <= s.size() - 1; l--, r++) {
                if (s.substr(l, 1) == s.substr(r, 1)) {
//                    cout<<"temp:"<<s.substr(l, r - l + 1)<<endl;
                    if (r - l + 1 > count) {
                        count = max(count, r - l + 1);
                        res = s.substr(l, r - l + 1);
//                        cout << "single:" << res <<", "<<"center:"<< s.substr(i, 1)<<endl;
                    }
                } else {
                    break;
                }
            }
        }
        // 双中心
        for (i = 0; i + 1 < s.size(); i++) {
            if (s.substr(i, 1) != s.substr(i + 1, 1)) { continue; } // 起步是2
            if (count < 2) {
                count = 2;
                res = s.substr(i, 2);
            }
            for (l = i - 1, r = i + 2; l >= 0 && r <= s.size() - 1; l--, r++) {
                if (s.substr(l, 1) == s.substr(r, 1)) {
                    if (r - l + 1 > count) {
                        count = max(count, r - l + 1);
                        res = s.substr(l, r - l + 1);
//                        cout << "double:" << res << endl;
                    }
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    string str;
    Solution s;
    while (cin >> str) {
        cout << s.longestPalindrome(str) << endl;
    }
    return 0;
}

pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}