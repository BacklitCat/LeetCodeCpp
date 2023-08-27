#include <vector>
#include <iostream> // stringstream
#include <queue> // queue,priority_queue
#include <numeric> // accumulate

using namespace std;

// HARD


class Solution {
public:
    int minOperations(vector<int> &nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);//有大数相加会爆int
        if (total < target) {
            return -1;
        }
        // 最大堆
        // 这里用最小堆是不行的，因为小数会被先用，剩下的数，较大数可能会被反复拆，但直接用大数可能操作数更少
        // 用最大堆，先弹掉比较大的数字，只留下和刚好够或多一点target，再先用大的再用小的
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());


        // 此时先用较大的，如果比当前元素大，就拆掉
        int count = 0;
        long long sum = 0;
        // 不断的取大数，加和
        while (true) {
            // pop 如果pop光也不够，则返回-1
//            if (pq.size() == 0) {
//                break;
//            }

            // pop掉大元素，直到不够为止
            while (total - pq.top() >= target) {
                total -= pq.top();
                pq.pop();
            }

            // 尝试加和
            if (sum + pq.top() == target) {
                return count;
            } else if (sum + pq.top() < target) {
                sum += pq.top();
                pq.pop();
            } else {
                //大数拆分
                int big_num = pq.top();
                if (big_num == 1) { // 1不许拆分
                    break; // 实际应该走不到这里
                }
                pq.pop();
                pq.emplace(big_num / 2);
                pq.emplace(big_num / 2);
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    auto nums = vector<int>{128, 1, 1, 128, 64};
//    cout << s.minOperations(nums, 4);
    nums = {128, 1024, 1073741824, 4194304, 268435456, 1024, 16, 1073741824, 131072, 4, 16777216, 67108864, 16777216,
            268435456, 1073741824, 256, 16, 67108864, 1048576, 16, 4, 4194304, 1024, 16, 262144, 1048576, 1024, 128,
            1073741824, 67108864, 65536, 128, 32768, 128, 32768, 8192, 256, 1024};
    cout << s.minOperations(nums, 38);
}
