#include <iostream>
#include <string>

using namespace std;

/*
class Solution {
public:
    // 回溯，极端用例会超时
    long long max_dist = 0;

    void backtrack(string &moves, int i, long long loc) {
        if (i == moves.size()) {
            max_dist = max(max_dist, abs(loc));
            return;
        }
        if (moves[i] == 'L') {
            loc--;
//            max_dist = max(max_dist, abs(loc));
            backtrack(moves, i + 1, loc);
        } else if (moves[i] == 'R') {
            loc++;
//            max_dist = max(max_dist, abs(loc));
            backtrack(moves, i + 1, loc);
        } else {
            // 向左
//            max_dist = max(max_dist, abs(loc-1));
            backtrack(moves, i + 1, loc - 1);
            // 取消，向右
//            max_dist = max(max_dist, abs(loc+1));
            backtrack(moves, i + 1, loc + 1);
        }
    }

    int furthestDistanceFromOrigin(string moves) {
        backtrack(moves, 0, 0);
        return max_dist;
    }
};
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        long l_count=0,r_count=0,any_count=0;
        for (auto c:moves){
            if(c=='L'){
                l_count++;
            }else if(c=='R'){
                r_count++;
            } else{
                any_count++;
            }
        }
        return abs(l_count-r_count)+any_count;
    }
};

int main() {
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.furthestDistanceFromOrigin(str);
    }

}