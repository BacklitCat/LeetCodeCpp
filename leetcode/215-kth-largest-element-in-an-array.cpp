#include <vector>
#include <cstdlib>
using namespace std;

// Mid 215 https://leetcode.cn/problems/kth-largest-element-in-an-array
class Solution {
public:
    int K = -1, res = -1;

    static int partition(vector<int> &nums, int l, int r) {
        int rd = rand() % (r - l + 1) + l;
        swap(nums[l],nums[rd]);
        int p = l, i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] >= nums[p]) { j--; }
            while (i < j && nums[i] <= nums[p]) { i++; }
            swap(nums[i], nums[j]);
        }
        swap(nums[p], nums[i]);
        return i;
    }

    void findK(vector<int> &nums, int l, int r) {
        if (l > r) { return; }
        if (res >= 0) { return; }
        int i = partition(nums, l, r);
        if (i == K) {
            res = i;
            return;
        } else if (i > K) { // 由于不需要排序，所以只查找一边
            findK(nums, l, i - 1);
        } else if (i < K) {
            findK(nums, i + 1, r);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        if (k < 0 || k > nums.size()) return -1;
        K = nums.size() - k;
        findK(nums, 0, nums.size() - 1);
        return nums[res];
    }
};