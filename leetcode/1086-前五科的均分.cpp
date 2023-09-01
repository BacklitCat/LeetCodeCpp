#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 排序版本
class Solution {
public:
    static bool cmp(vector<int> &item1, vector<int> &item2) {
        if (item1[0] == item2[0]) { return item1[1] > item2[1]; } // 成绩降序
        return item1[0] < item2[0]; // id升序
    }

    vector<vector<int>> highFive(vector<vector<int>> &items) {
        // 排序
        sort(items.begin(), items.end(), cmp);

        // for(auto item:items){
        //     cout << item[0]<<" "<<item[1]<<endl;
        // }

        vector<vector<int>> ret;
        int count = 0, last_id = -1, stu_sum = 0;
        for (int i = 0; i < items.size(); i++) {
            auto item = items[i];
            // cout << item[0]<<" "<<item[1]<< " "<<count << " "<< last_id<< endl;
            if (item[0] != last_id) { // 第1次
                last_id = item[0];
                stu_sum = item[1];
                count = 1;
            } else { //  if (item[0] == last_id)
                count++;
                if (count <= 5){ // 2-5次
                    stu_sum += item[1];
                }
                if(count == 5){ // 第5次
                    ret.push_back({last_id,stu_sum/5});
                }
            }
        }
        return ret;
    }
};

// map + 大根堆
class Solution1 {
        public:
        vector<vector<int>> highFive(vector<vector<int>>& items) {
            // result 需要按 IDj  递增的 顺序排列 。
            map<int, priority_queue<int>> m;
            for (const auto& i : items) m[i[0]].emplace(i[1]);

            vector<vector<int>> ans;
            for (auto & kv : m) {
                auto id  = kv.first;
                auto q = kv.second;
                int s = 0;
                for (int i = 0; i < 5; ++i) {
                    s += q.top(); q.pop();
                }
                ans.push_back({id, s / 5});
            }

            return ans;
        }
};
