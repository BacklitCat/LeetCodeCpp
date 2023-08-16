#include <vector>
#include <iostream> // stringstream

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n==1||n==0||n==-1) return true;
        vector<int> div{2, 3, 5};
        int remain = 0;

        for (int i = 0; i < 3;) {
//            cout << "r:"<<remain<<endl;
            remain = n % div[i];
            if (remain == 0) {
                n = n / div[i];
                if (n==1){
                    return true;
                }
                continue;
            } else {
                i++;
            }
        }

        return remain == 0;
    }
};

int main(){
    Solution s;
    cout << s.isUgly(6) << endl;
}