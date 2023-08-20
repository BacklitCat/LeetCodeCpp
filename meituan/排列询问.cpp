#include <iostream>
#include <string>
using namespace std;


/*
小美的排列询问
小美拿到了一个排列。她想知道在这个排列中，x和y是否是相邻的。你能帮帮她吗？
排列是指一个长度为n的数组，其中 1 到n每个元素恰好出现一次。
 */
const int N = 2e6;
int nums[N];

// 打卡题
int main() {
    int n, i, x, y;
    string ans;
    while (cin >> n) {
        i = 0;
        ans = "";
        while (i < n) {
            cin >> nums[i];
            i++;
        }
        cin >> x >> y;
        for (int i=0;i<n-1;i++){
            if (nums[i]==x){
                if (i-1>=0 && nums[i-1]==y || nums[i+1]==y){
                    ans =  "Yes";
                    break;
                }
            }
        }
        if(ans == ""){
            ans = "No";
        }
        cout << ans;
    }
}