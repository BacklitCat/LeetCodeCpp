#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    double fastPow(double x, long long n) {
        double ret = 1, base = x;
        while (n > 0) {
            if (n & 1) {
                ret *= base;
            }
            base *= base;
            n >>= 1;
        }
        return ret;
    }

    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }else if(x==1){
            return x;
        } else if (n > 0) {
            return fastPow(x, n);
        } else {
            long long n_ = n;
            return fastPow(1 / x, -n_);
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(2, 0) << " = " << 1 << endl;
    cout << s.myPow(2, 1) << " = " << 2 << endl;
    cout << s.myPow(2, 2) << " = " << 4 << endl;
    cout << s.myPow(2, 3) << " = " << 8 << endl;
    cout << s.myPow(2, 4) << " = " << 16 << endl;
    cout << s.myPow(2, 9) << " = " << 512 << endl;
    cout << s.myPow(2, 10) << " = " << 1024 << endl;
    cout << s.myPow(8.88023, 3) << " = " << 700.28148 << endl;
    cout << s.myPow(2, -2) << " = " << 0.25 << endl;
}

/*
Line 23: Char 35: runtime error: negation of -2147483648 cannot be represented in type 'int';
 cast to an unsigned type to negate this value to itself (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:32:35
最后执行的输入
添加到测试用例
x = 2.00000
n = -2147483648

真的恶毒，观察到输入范围：
 -231 <= n <= 231-1
 所以当n=-2147483648时，取反会超出2147483647，报错
 只能用long long存n
*/