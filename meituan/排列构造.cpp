#include <iostream>

using namespace std;

/*
 小美的排列构造
 
 两两求和尽可能相近

 2
 1 2

 3
 2 1 3

 4
1 4 2 3   4 1 3 2
 5 6 5    5  4 5

规律：小大小大
*/

int main() {
    int n, x, y;
    while (cin >> n) {
        x = 1, y = n;
        while (x < y) {
            cout << x++ << " " << y-- << " ";
        }
        if (n % 2 == 1) {
            cout << (n + 1) / 2;
        }
    }
}
