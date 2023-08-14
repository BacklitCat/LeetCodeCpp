#include<vector>
#include<iostream>
#include<string>
#include <sstream>
#include "binary_search.h"

void check(vector<int> &nums, int true_ans, int ans, stringstream &err) {
    if (ans != true_ans) {
        err << "[err], nums:[ ";
        for (auto num: nums) {
            err << num << " ";
        }
        err << "], want: " << true_ans << ", get: " << ans << endl;
    }
}

int main() {
    vector<int> nums;
    int true_ans, ans;
    stringstream err;

    nums = {1, 2, 2, 4, 5, 6};
    true_ans = 1;
    ans = binarySearchLowerBound(nums, 2);
    check(nums, true_ans, ans, err);

    true_ans = -1;
    ans = binarySearch(nums, 3);
    check(nums, true_ans, ans, err);

    cout << err.str();
}