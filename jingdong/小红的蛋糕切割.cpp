#include <vector>
#include <iostream>

using namespace std;

const int N = 1e3 + 1;

long long me[N + 1][N + 1]{0}; // 数组
long long prefix[N + 1][N + 1]{0}; // 二维前缀和

long long cut(int n, int m, int i, int j) { //在i行j列开一刀
    // 划分为四块
    // 先计算四块的值
    // 再计算每一块与其他四块的差值

    // i = 1...n-1
    long long a, b, c, d;
    a = prefix[i][j];
    b = prefix[i][m] - a;
    c = prefix[n][j] - a;
    d = prefix[n][m] - b - c + a;
    long long aa = abs(b+c+d-a),bb = abs(a+c+d-b),cc = abs(a+b+d-c),dd = abs(a+b+c-d);
    return min(min(min(aa,bb),cc),dd);
}

int main() {
    int n, m;//n 行 m 列
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> me[i][j];
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout << me[i][j];
//        }
//    }
    // 计算二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = me[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i-1][j - 1];
        }
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            cout << prefix[i][j];
//        }
//    }
    long long min_diff = 0x7fffffff;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout <<"cut "<< i<<" "<< j<<" "<< cut(n,m,i,j)<<endl;
            min_diff = min(min_diff, cut(n,m,i,j));
        }
    }
    cout << min_diff;
    return 0;
}