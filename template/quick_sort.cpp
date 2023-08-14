#include<vector>
#include <algorithm>
#include<iostream>
#include <sstream>
#include "quick_sort.h"

void check(vector<int> &nums, vector<int> &true_ans, vector<int> &ans, stringstream &err) {
    if (ans != true_ans) {
        err << "[err], nums:[ ";
        for (auto num: nums) {
            err << num << " ";
        }
        err << "], want:[ ";
        for (auto num: true_ans) {
            err << num << " ";
        };
        err << "], get: ";
        for (auto num: ans) {
            err << num << " ";
        };
        err << "]" << endl;
    }
}

int main() {
    vector<int> nums,true_ans,ans;
    stringstream err;
    nums = {1, 7, 1, 4, 5, 4, 6, 6, 7};
    true_ans = nums;
    ans = nums;
    sort(true_ans.begin(),true_ans.end());

    partition(ans, 0, nums.size() - 1);

    check(nums,true_ans,ans,err);
    cout << err.str();
    return 0;
}