#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    double fastPow(unordered_map<int, double> &hash_map, double x, int n) {
        if (hash_map.find(n) != hash_map.end()) {
            return hash_map[n];
        }

        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else if (n == 2) {
            return x * x;
        }

        double temp = fastPow(hash_map, x, n / 2);
        double ret;
        if (n % 2 == 0) {
            ret = temp * temp;
        } else {
            ret = temp * temp * x;
        }
        hash_map[n] = ret;
        return ret;
    }

    double myPow(double x, int n) {
        unordered_map<int, double> hash_map;
        if (n >= 0) {
            return fastPow(hash_map, x, n);
        } else {
            return fastPow(hash_map, 1 / x, n);
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
}