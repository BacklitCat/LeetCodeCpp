#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>
#include <string>

using namespace std;

/*
 小美的字符串匹配度
 https://www.nowcoder.com/exam/test/51799538/summary?pid=51799538&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany%3FcurrentTab%3Drecommand%26jobId%3D100%26selectStatus%3D0%26tagIds%3D179&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
 */

int main() {
    int n;
    int set_s[26], set_t[26];
    // pair<char,char>
    set<pair<char, char>> hash_set;
    unordered_set<char> str_s_set;
    string str_s, str_t;
    int sum = 0, extra = 0;
    while (cin >> n) { // 注意 while 处理多个 case
        hash_set.clear();
        str_s_set.clear();
        sum = 0, extra = 0;
        cin >> str_s >> str_t;
        for (int i = 0; i < n; i++) {
            if (str_s[i] == str_t[i]) sum++;
            else if (extra != 2) {
                if (hash_set.find(pair<char, char>{str_t[i], str_s[i]}) != hash_set.end()) {
                    extra = 2;
                } else if (str_s_set.find(str_t[i])!=str_s_set.end()){
                    extra = 1;
                }
                hash_set.emplace(pair<char, char>{str_s[i], str_t[i]});
                str_s_set.emplace(str_s[i]);
            }
        }
        cout << sum + extra;

//        cout << str_s << str_t << endl;
    }
}