// 这个思路有问题

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

int nums[N];

int count_max_show(int n) {
    int count = 0, num = -1, max_count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != num) {
            num = nums[i];
            count = 1;
        } else {
            count++;
        }
        max_count = max(count, max_count);
    }
    return max_count;
}

int main() {
    int n, count1, count2;
    long long sum, avg, remain, re, diff;
    while (cin >> n) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
        // 大数减小，小数增加，向平均值靠拢
        // 加一减一实际上是把一个1挪给其他数字
        // 尽量往平均值靠
        avg = sum / n;
        remain = sum % n;

        count2 = max(remain, n - remain);

        sort(nums, nums + n);
        count1 = count_max_show(n);

        for(int i=0;i<n;i++){
            cout << nums[i]<<" ";
        }cout<<endl;

        cout << "count1:"<<count1<< " count2:"<<count2<<endl;

        if (count1 == count2){
            cout << 0 ;
            continue;
        }

        diff = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (remain > 0) {
                re = 1;
                remain--;
            } else {
                re = 0;
            }
            diff += abs(nums[i] - avg - re);
        }
        // diff / 2 就是调整次数
        cout << diff / 2;
    }
    return 0;
}