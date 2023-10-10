#include <vector>

using namespace std;

/* 升序 下一个排列
 * 1.从右边找第一个升序的数对a[i] a[j]，找到后，j右边全是降序的
 * 2.从j右边，从右边找第一个大于a[i]的a[k]，i k 交换位置
 *   这一步要找尽量小的大数，现在 i k 位置都是小于j的，且右侧依旧全是降序的
 * 3.从j位置，逆序右侧，将降序变为升序，即找到了下一个升序
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. 从右找到第1对升序
        int i,j=nums.size()-1,k;
        while (j-1>=0){
            if (nums[j-1]<nums[j]){
                break;
            }
            j--;
        }

        if(j==0){ // 代表全逆序
            reverse(nums,0,nums.size()-1);
            return;
        }

        // 2. 从j向右找第1个比i大
        i=j-1;
        k=nums.size()-1;
        while (k<nums.size() && k>j){
            if(nums[k] > nums[i]){
                break;
            }
            k--;
        }
        // ?会不会找不到？
        swap(nums[i],nums[k]);

        // 3. 逆序右侧
        reverse(nums,j,nums.size()-1);
    }

    void reverse(vector<int> &nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};

int main(){
    Solution ss;
    vector<int> nums = {3,2,1};
    ss.nextPermutation(nums);
}