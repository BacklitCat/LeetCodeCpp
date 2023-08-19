#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<char, int> hash_map = {{'I', 1},
                                     {'V', 5},
                                     {'X', 10},
                                     {'L', 50},
                                     {'C', 100},
                                     {'D', 500},
                                     {'M', 1000}};

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i - 1 >= 0) && ((hash_map[s[i]] == hash_map[s[i - 1]] * 5) ||
                                 (hash_map[s[i]] == hash_map[s[i - 1]] * 10))) {
                ret += hash_map[s[i]] - 2 * hash_map[s[i - 1]];
            } else {
                ret += hash_map[s[i]];
            }
        }
        return ret;
    }
};