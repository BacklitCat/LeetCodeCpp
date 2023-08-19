#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size()==1){return 1;}
        int l=-1,r=-1;
        for(int i=s.size()-1;i>=0;i--){
            // l:第一个左空右不空 r:左不空
            if(s[i]!=' '&&r==-1){r=i;}
            if(i+1<s.size()&&s[i]==' '&&s[i+1]!=' '&&l==-1){l=i+1;}
            else if(i==0&&s[i]!=' '&&l==-1){l=0;}
            if (l!=-1&&r!=-1){break;}
        }
        // cout << "l="<<l<<" r="<<r<<endl;
        return r-l+1;
    }
};