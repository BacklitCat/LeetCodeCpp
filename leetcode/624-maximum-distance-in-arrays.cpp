#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// 624 Mid https://leetcode.cn/problems/maximum-distance-in-arrays
// [[0,5],[1,4]] 0 4
// [[-10,-9,-9,-3,-1,-1,0],[-5],[4],[-8],[-9,-6,-5,-4,-2,2,3],[-3,-3,-2,-1,0]] 13 14
class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int low_value = arrays[0].front(), high_value = arrays[0].back();
        int dist = 0; // 对应下标0，不能从一个地方取
        for (int i = 1; i < arrays.size(); i++) { // 从第1(从0计数)个数组开始遍历
            // 更新最大距离
            dist = max(dist, max(high_value - arrays[i].front(), arrays[i].back() - low_value));
            // 更新备选边界
            low_value = min(low_value, arrays[i].front());
            high_value = max(high_value, arrays[i].back());
        }
    }

    return
    dist;
}

};

/*
input：第1行数组个数，第2行数组长度，后续是数组
3
3 2 3
1 2 3
4 5
1 2 3
output：5-1=4
4
input：第1行数组个数，第2行数组长度，后续是数组
2
3 2
1 2 3
4 5
output：5-1=4
4
input：第1行数组个数，第2行数组长度，后续是数组
3
3 2 3
1 2 3
4 5
2 2 6
output：6-1=5
5
 */
int main() {
    cout << "input:" << endl;
    int M;
    cin >> M;
    vector<int> length(M);
    for (int i = 0; i < M; i++) {
        cin >> length[i];
    };

    vector<vector<int>> data(M);
    for (int i = 0; i < M; i++) {
        vector<int> row(length[i]);
        for (int j = 0; j < length[i]; j++)
            cin >> row[j];

        data[i] = row;
    }
    cout << "check:" << endl;
    cout << M << endl;
    for (int i = 0; i < M; i++) {
        cout << length[i] << " ";
    };
    cout << endl;
    for (auto row: data) {
        for (auto col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "output:" << endl;
    Solution s;
    int res = s.maxDistance(data);
    cout << res;
}