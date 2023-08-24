#include <iostream>
#include <string>

using namespace std;

// 牛客 美团24秋招第2场第5题
// 送分题

int nums[100];

const string YES = "Yes";
const string NO = "No";

// 判断是否为非降序
string is_valid(int n) {
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            return NO;
        }
    }
    return YES;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t, n, k, u, v;

    cin >> t;

    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int i = 0; i < k; i++) {
            cin >> u >> v;
            nums[u - 1]++;
            nums[v - 1]--;
        }
        for (int i = 0; i < n; i++) {
            cout << nums[i];
        }
        cout << is_valid(n) << endl;
    }
    return 0;
}