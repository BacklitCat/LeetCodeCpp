#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> numsMap;
        int i = 0;
        for (auto num: nums) {
            // 存在，返回
            if (numsMap.count(target-num)>0){
                return {i,numsMap[target-num]};
            }
            // 不存在，插入
            numsMap[num] = i;
            i++;
        }
        return {};
    }
};