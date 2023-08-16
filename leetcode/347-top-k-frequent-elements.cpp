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
    // pair<int,int> <元素，频数>
    static bool cmp(pair<int,int> &m, pair<int,int> &n){
        return  m.second > n.second; // 默认是从大到小，这次是最小堆，需要从小到大
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash_map;
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&cmp)> q(cmp);
        vector<int> res;

        for(auto num : nums){
            hash_map[num] += 1;
        }

        for(auto &kv : hash_map){
            int num = kv.first, count = kv.second;
            if(q.size() < k){
                q.emplace(pair<int,int>{num,count});
                continue;
            }
            if(q.top().second >= count){
                continue;
            }
            q.pop();
            q.emplace(pair<int,int>{num,count});
        }

        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,2,3,4,4,4,5};
    vector<int> res = s.topKFrequent(nums,2);
    for (auto num: res) {
        cout << num << " ";
    }
    cout << endl;
}