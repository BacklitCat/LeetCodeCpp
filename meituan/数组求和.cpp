#include <iostream>

using namespace std;

// 牛客 美团24秋招第2场第1题
int main() {
    long long n, num, last_num, sum, a, b, max_multi;
    while (cin >> n) {
        sum = 0, max_multi = 0, last_num = 0;
        for (int i = 0; i < n; i++) {
            cin >> num;
            sum += num;

            if (last_num * num > max_multi) {
                a = last_num;
                b = num;
                max_multi = a * b;
            }

            last_num = num;
        }

        sum = sum - a - b + a*b;
        cout << sum;
    }
    return 0;
}