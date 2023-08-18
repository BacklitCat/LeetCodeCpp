#include <vector>
#include <iostream> // stringstream
#include <algorithm> //sort
#include <string> //stoi,memset
#include <unordered_map>
#include <unordered_set>
#include <cstdlib> // rand
#include <queue> // queue,priority_queue
#include <utility> // pair

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low=0x7fffffff, profit = 0;
        for (auto price: prices) {
            // 如果当前价格是最新的低价格，则买入
            if (price < low){
                low = price;
                continue;
            }
            // 如果今天卖出，看看能获利多少，保存最大获利
            if(price - low > profit){
                profit = price - low;
            }
        }
        return profit;
    }
};