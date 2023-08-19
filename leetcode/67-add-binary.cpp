#include <string>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:

    pair<char, int> add(char a, char b, int d) {
        if (d == 0) {
            if (a == '0' && b == '0') {
                return pair<char, int>{'0', 0};
            } else if (a == '1' && b == '1') {
                return pair<char, int>{'0', 1};
            } else {
                return pair<char, int>{'1', 0};
            }
        } else {
            if (a == '0' && b == '0') {
                return pair<char, int>{'1', 0};
            } else if (a == '1' && b == '1') {
                return pair<char, int>{'1', 1};
            } else {
                return pair<char, int>{'0', 1};
            }
        }
    }

    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, d = 0;
        pair<char, int> p;
        stringstream ss;
        string ret;
        while (i >= 0 && j >= 0) {
            p = add(a[i], b[j], d);
            ss << p.first;
            d = p.second;
            i--;
            j--;
        }
        while (i >= 0) {
            p = add(a[i], '0', d);
            ss << p.first;
            d = p.second;
            i--;
        }
        while (j >= 0) {
            p = add('0', b[j], d);
            ss << p.first;
            d = p.second;
            j--;
        }
        if (d == 1) {
            ss << '1';
        }
        ret = ss.str();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};