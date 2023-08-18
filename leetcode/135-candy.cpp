#include <vector>
#include <iostream>

using namespace std;

// Hard 135 https://leetcode.cn/problems/candy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {1, 7, 1, 4, 5, 4, 6, 6, 7};
    ratings = {7,1, 1, 4};
    cout << s.candy(ratings) << endl;
    ratings = {1, 2, 2};
    cout << s.candy(ratings) << endl;
    ratings = {1,3,2,2,1};
    cout << s.candy(ratings) << endl;
    ratings = {1,3,2,2,1};
    cout << s.candy(ratings) << endl;

}
