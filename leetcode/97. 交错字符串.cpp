#include <string>
#include <vector>

using namespace std;

// 回溯超时
class SolutionTimeout {
public:
    bool ret = false;

    void backtrack(string &s1, string &s2, string &s3, int s1_loc, int s2_loc, int s3_loc) {
        if (ret) {
            return;
        }
        if (s1_loc == s1.size() && s2_loc == s2.size()) {
            ret = true;
            return;
        }

        if (s1_loc < s1.size() && s1[s1_loc] == s3[s3_loc]) {
            backtrack(s1, s2, s3, s1_loc + 1, s2_loc, s3_loc + 1);
        }
        if (s2_loc < s2.size() && s2[s2_loc] == s3[s3_loc]) {
            backtrack(s1, s2, s3, s1_loc, s2_loc + 1, s3_loc + 1);
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        backtrack(s1, s2, s3, 0, 0, 0);
        return ret;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector < vector <int> > (s1.size() + 1, vector <int> (s2.size() + 1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[n][m];
    }
};