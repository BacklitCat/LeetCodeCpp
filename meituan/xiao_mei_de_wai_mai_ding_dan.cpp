#include <iostream>
#include <cstdio>

using namespace std;

/*
 小美的外卖订单
 https://www.nowcoder.com/exam/test/51799538/summary?pid=51799538&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany%3FcurrentTab%3Drecommand%26jobId%3D100%26selectStatus%3D0%26tagIds%3D179&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
 注意，输入可能脏，要校验
 */
int main() {
    int n;// 总数
    double a, b, x, y; // 原价，单价；满x减y
    double sum_a, price_a, sum_b;
    bool err;
    while (cin >> n) { // 注意 while 处理多个 case
        err = false;
        sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (b > a || a <= 0 || b <= 0) {
                err = true;
            }
            sum_a += a;
            sum_b += b;
        }
        cin >> x >> y;
        if (x <= 0 || y <= 0 || y > x) {
            err = true;
        }
        // price_a = sum_a - (int)(sum_a / x) * y;
        price_a = sum_a > x ? sum_a - y : sum_a;
        if (err) {
            cout << "error";
        } else if (price_a < sum_b) {
            printf("%.2f", price_a);
        } else {
            printf("%.2f", sum_b);
        }
    }
}
// 64 位输出请用 printf("%lld")