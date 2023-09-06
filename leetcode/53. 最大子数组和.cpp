#include <vector>
#include <climits> // INT_MIN INT_MAX

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ret = INT_MIN, temp = 0;
        for (auto const &num: nums) {
            // 如果当前 num >=0 可以添加进本次子数组
            if (num >= 0) {
                if(temp<0){ // 如果前面子数组已经是负的了，则从本次重新开始
                    temp = num;
                }else{
                    temp += num;
                }
            }else{ // num < 0
                if (temp + num <=0){ // 如果添加本次num会导致<=0 则不添加 重新开始子数组
                    temp = num;
                }else{
                    temp += num;
                }
            }
            ret = max(ret, temp);
        }
        return ret;
    }
};

class SolutionStd53 {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
