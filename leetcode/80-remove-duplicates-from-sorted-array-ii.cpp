#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) { return nums.size(); }
        // i 待写入 j 待探索 count指nums[j]出现的次数
        int i = 0, j = 1, count = 1;
        while (j < nums.size()) {
            // 更新count
            if (nums[j] == nums[j - 1]) {
                count++;
            } else { count = 1; }

            if (count <= 2) {
                nums[++i] = nums[j++];
            } else{
                j++;
            }
        }
        return i + 1;
    }
};