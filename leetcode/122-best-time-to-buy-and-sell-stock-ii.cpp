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
        // 买下每一段上升区间
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};