#include <iostream>
#include <cstring>
#include <cstdlib>

// 蛋糕切割 没ac 再看看吧！

using namespace std;

const int N = 1e3;

// 又卡long long了
long long row[N], col[N]; // 存储每行/列的和
long long d[N]; //临时存储前缀和

// 计算前缀和，存储到prefix
// 计算到第i位置时，和不含i
void prefix_sum(long long *arr, long long *prefix, int n) {
    // 确保 n > 1
    prefix[0] = 0;
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += arr[i - 1];
        d[i] = sum;
    };
}

int min_diff(long long *arr, int n) {
    if (n == 1) { return 0x7fffffff; } // 没法分割
    else if (n == 2) { return abs(arr[0] - arr[1]); } // 快速分割

    prefix_sum(arr, d, n);

    // 计算后缀和，含i位置
    long long back = 0, ret = 0x7fffffff;
    for (int i = n - 1; i >= 1; i--) {
        back += arr[i];
        ret = min(ret, abs(back - d[i]));
    };
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, num; // 行列
    while (cin >> n >> m) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
//                cout << "(i,j)=" << i<<" "<<j<<endl;
                cin >> num;
                row[i] += num;
                col[j] += num;
            }
        }
//        cout <<"ok";
//        cout << min_diff(row,n)<<endl;
//        cout << min_diff(col,m)<<endl;
        if (n == 1 && m == 1) {
            cout << num;
        } else {
            cout << min(min_diff(row, n), min_diff(col, m));
        }
    }
}