#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<int, string> hash_map = {{1,    "I"},
                                       {4,    "IV"},
                                       {5,    "V"},
                                       {9,    "IX"},
                                       {10,   "X"},
                                       {40,   "XL"},
                                       {50,   "L"},
                                       {90,   "XC"},
                                       {100,  "C"},
                                       {400,  "CD"},
                                       {500,  "D"},
                                       {900,  "CM"},
                                       {1000, "M"}};

vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            int count = num / nums[i];
            while (count >= 1) {
                ss << hash_map[nums[i]];
                num -= nums[i];
                count--;
            }
        }
        return ss.str();
    }
};