#include <iostream>

using namespace std;

const int N = 1e5;
long long nums[N];

int main() {
    int i, n, x, y;
    long long forward, backward; // 数据很大，你忍一下
    while (cin >> n) {
        i = 0;
        forward = 0, backward = 0;
        while (i < n) {
            cin >> nums[i];
            i++;
        }
        cin >> x >> y;
        //forward
        for (int i = x - 1; i != y - 1; i = (i + 1) % n) {
            // cout <<"forward i="<<i<<endl;
            forward += nums[i];
        }
        // cout <<"forward="<<forward;
        //backward
        for (int i = x - 1; i != y - 1;) {
            // cout <<"backward i="<<i<<endl;
            if (i != 0) {
                backward += nums[i - 1];
            } else {
                backward += nums[n - 1];
            }
            i--;
            if (i == -1) { i = n - 1; }
        }
        // cout <<" backward="<<backward;
        cout << min(forward, backward);
    }
}