#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> hash_set;
        int num = 1;
        long long sum=0;
        while (hash_set.size()<n) {
            // 先判断是否能加入
            if(hash_set.find(target-num)!=hash_set.end()){
                num++;
                continue;
            }
            // 加入num
            sum += num;
            hash_set.emplace(num);

            // 找下一个num
            num++;
        }
        return sum;
    }
};
