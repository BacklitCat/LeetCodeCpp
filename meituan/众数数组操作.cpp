#include <iostream>
#include <vector>
#include <numeric> // accumulate
#include <algorithm>
#include <functional>

using namespace std;

// 美团20230819笔试 小美的数组操作
// 答案验证过是正确的 但还是有些不明白
// https://www.nowcoder.com/exam/test/72633598/detail?pid=52007812&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
// https://mp.weixin.qq.com/s/CChKz8UOgjmaXZbaYsnbww


long long comp(vector<long long> &nums, int l, int r) {
    // 计算给定[l,r]范围内的和
    long long tot = 0;
    for (int i = l; i <= r; ++i) {
        tot += nums[i];
    }

    // 计算平均数 与操作数 这里真看不懂了
    long long avg = tot / (r - l + 1);
    long long avg2 = avg + 1;
    long long a = 0;
    long long b = 0;
    long long c = 0;
    long long d = 0;

    for (int i = l; i <= r; ++i) {
        if (nums[i] >= avg) a += nums[i] - avg;
        else b += avg - nums[i];
        if (nums[i] >= avg2) c += nums[i] - avg2;
        else d += avg2 - nums[i];
    }
    return min(max(a, b), max(c, d));
};

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    long long sum = accumulate(nums.begin(), nums.end(), (long long) 0);

    // 如果能整除，则代表众数可以是平均数，累加操作数
    if (sum % n == 0) {
        long long avg = sum / n;
        long long ans = 0;
        for (auto a: nums) {
            ans += abs(a - avg);
        }
        cout << ans / 2 << endl;
        return 0;
    }

    // 如果不能整除，则排序，利用有序
    sort(nums.begin(), nums.end());

    // 如果所有的数字加起来切好是n的倍数，那么是肯定可以把所有数字归为同一个数字的。
    // 否则，我们是一定可以产出n-1个众数的，关键就是排除哪个元素呢？排除的元素要使得最后的操作次数尽可能少，
    // 显然是应该排除最大或者最小（与平均数偏移最多。）枚举这两种情况即可。

    long long res1 = comp(nums, 0, n - 2); // 剔除最大值
    long long res2 = comp(nums, 1, n - 1); // 剔除最小值
    cout << min(res1, res2) << endl;
    return 0;
}