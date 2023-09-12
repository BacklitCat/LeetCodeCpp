#include <vector>
#include <iostream> // stringstream
#include <algorithm> //sort,min_element,max_element
#include <string> //stoi,memset
#include <cstring> //memset
#include <unordered_map>
#include <unordered_set>
#include <cstdlib> // rand
#include <queue> // queue,priority_queue
#include <utility> // pair
#include <cstdio> // printf
#include <cstdint> // uint32_t
#include <cmath> // pow
#include <numeric> // accumulate

using namespace std;

static long long cal(long long l1, long long r1, long long l2, long long r2){
    // 合并区间
    long long left=max(l1,l2);
    long long right=min(r1,r2);
    if (left > right){
        return -1;
    }
    return right *2;
}
// 打卡题
int main(){
    long long arr[6],max_v=0;
    for(int i=0;i<6;i++){
        cin >> arr[i];
    }
    max_v = max(max(cal(arr[0],arr[1],arr[2],arr[3]),
                    cal(arr[0],arr[1],arr[4],arr[5])),
                cal(arr[2],arr[3],arr[4],arr[5]));
    cout << max_v;
    return 0;
}
