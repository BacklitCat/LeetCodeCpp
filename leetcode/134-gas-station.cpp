#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // gas[i]-cost[i]
        int start = 0, i = 0, remain = 0;

        // 快速判断能否走通
        for (i = 0; i < gas.size(); i++) {
            remain += (gas[i] - cost[i]);
        }
        if (remain < 0) {
            return -1;
        }

        i = 0;
        remain = 0;
        while (true) {
            // 更新当前收益
            remain += (gas[i] - cost[i]);
//            cout << "i=" << i << " remain=" << remain << endl;
            i = (i + 1) % gas.size();
            if (remain < 0) { // 继续走
                remain = 0;
                start = i;
                continue;
            }

            // 回到出发点
            if (start == i) {
                return start;
            }

        }
    }
};

int main() {
    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << s.canCompleteCircuit(gas, cost);
}