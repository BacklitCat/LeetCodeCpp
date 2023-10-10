#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0);
        return res;
    }

    void backtrack(vector<vector<int> > &res, vector<int> &nums, int idx){
        if(idx==nums.size()){
            res.push_back(nums);
        }

        // 循环维护每一个位置
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            backtrack(res,nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
};