#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        // h=1 1 （>=，下同）
        // h=2 2 2
        // h=3 3 3 3
        sort(citations.begin(), citations.end());
        int h = 1, n = min((int) citations.size(), citations.back()); // 上限
        int i = 0; // 遍历指针
        while (h <= n) {
            // 找到最后一个满足当前h的边界
            while (i < citations.size() && citations[i] < h) { i++; }
            // 此时i及右边的元素都是>=h的，如果数量满足要求，则当前h合格，否则不合格
            if (citations.size() - i >= h) {
                h++;
                continue;
            } else {
                break;
            }
        }
        return h-1;
    }
};