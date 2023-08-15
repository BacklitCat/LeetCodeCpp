#include <vector>
#include <iostream> // stringstream
#include <string> //stoi,memset

using namespace std;

class Solution {
public:
    void backtrack(vector<string> &res, string &str, int l, int r, int N) {
        if (l == r && r == N) {
            res.push_back(str);
            return;
        }
        // 左括号
        if (l < N) {
            str.push_back('(');
            backtrack(res, str, l + 1, r, N);
            str.pop_back();
        }
        // 右括号
        if (r < l) {
            str.push_back(')');
            backtrack(res, str, l, r + 1, N);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrack(res, str, 0, 0, n);
        return res;
    }

};

int main() {
    Solution s;
    vector<string> res;
    res = s.generateParenthesis(1);
    for (const auto &str: res) {
        cout << "\"" << str << "\"";
    }
    cout << endl;
    res = s.generateParenthesis(2);
    for (const auto &str: res) {
        cout << "\"" << str << "\"";
    }
    cout << endl;
}
