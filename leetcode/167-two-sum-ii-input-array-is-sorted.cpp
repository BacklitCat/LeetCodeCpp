#include<vector>

using namespace std;

// Mid 167 https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 双指针，这是mid?
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l+1, r+1};
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            }
        }
        return {};
    }
};