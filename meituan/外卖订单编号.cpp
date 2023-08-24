#include <iostream>

using namespace std;

// 打卡题
// 牛客 美团24秋招第2场第4题

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int q;
    cin >> q;
    long long m, x, res;
    while (cin >> m >> x) {
        res = x % m;
        res = (res == 0) ? m : res;
        cout << res << endl;
    }
    return 0;
}