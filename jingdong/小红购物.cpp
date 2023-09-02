#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e6+1;

long long a[N];

static bool cmp(vector<long long> & item1, vector<long long> & item2){
    // 根据价格升序，同样的优惠券门槛按照优惠的价格降序
    if (item1[0]==item2[0]){
        return item2[1] > item1[1];
    }
    return item1[0] < item2[0];
}

long long binSearch(vector<vector<long long >> &nums, long long target) {
    long long low = 0, high = nums.size(), mid = -1;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (nums[mid][0] == target) { // 收缩左
            low = mid + 1;
        } else if (nums[mid][0] < target) {
            low = mid + 1;
        } else if (nums[mid][0] > target) {
            high = mid;
        }
    }
    return low - 1;
}

int main(){
    long long m,n,i=0,b,c;
    cin >> n >> m; // n 个商品
    while (i<n){ // 从0计数
        cin >> a[i];
        i++;
    }
    i=0;
    vector<vector<long long>> cop(m);
    while (i<m){ // 从0计数
        cin >> b >> c;
        cop[i] = {b,c};
        i++;
    }
    sort(cop.begin(),cop.end(), &cmp);
//    cout << "sort"<<endl ;
//    for (auto item:cop){
//        cout << item[0]<<" " <<item[1]<<endl;
//    }

    long long sum=0;
    for(i=0;i<n;i++){
        // 寻找最优优惠
        long long max_b=0;
//        for(int j=0;j<m;j++){ // 超时 这里可以二分优化 找到价格上界优惠券
//            if (cop[j][0] > a[i]){
//                break;
//            }
//            // >
//            max_b = max(max_b,cop[j][1]);
//        }
        long long loc = binSearch(cop,a[i]);
        // 从loc位置往前找，只到优惠券门槛小于已有的优惠金额
        for(int j=loc;j>=0 && j<cop.size();j--){
            if (cop[j][0] < max_b){
                break;
            }
            max_b = max(max_b,cop[j][1]);
        }
//        cout << "a[i]="<< a[i]<<" max_b="<<max_b<<endl;
        sum +=(a[i] - max_b);
    }
    cout << sum;
    return 0;
}