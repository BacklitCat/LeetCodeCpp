#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 牛客 美团24秋招第2场第3题
// 字串 联想前缀和 前缀和定义要清晰 注意边界

const int N = 2000+1;
int one[N], zero[N]; // 定义 one[i] 为到i位置时，与10101...串不相符的字符个数, i从1计数
char num[2]{'1', '0'};

void build_prefix(string &str) {
    memset(one, 0, sizeof one);
    memset(zero, 0, sizeof zero);

    for (int i = 1; i <= str.size(); i++) {
        one[i] += one[i - 1] + (str[i-1] != num[(i+1) % 2]);
        zero[i] += zero[i - 1] + (str[i-1] != num[i % 2]);
    }
}

void print_prefix(int n) {
    for (int i = 0; i <= n; i++) {
        cout << one[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << zero[i] << " ";
    }
    cout << endl;
}

int main() {
    string str;
    while (cin >> str) {
//        cout << str;
        build_prefix(str);
//        print_prefix(str.size());
        int sum = 0;
        for (int len = 2; len <= str.size(); len++) {
            for (int start = 0; start + len <= str.size();start++) {
                sum += min(one[start+len]-one[start],zero[start+len]-zero[start]);
//                cout << min(one[start+len]-one[start],zero[start+len]-zero[start])<<" ";
            }
        }
        cout << sum;
    }
}

/*
 10001
 10101 0 0 0 1 1 1
 01010 0 1 2 2 3 4
 */