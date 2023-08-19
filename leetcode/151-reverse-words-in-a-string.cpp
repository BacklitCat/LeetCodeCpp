#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        // 遍历单词
        // i寻找第一个非空，j寻找第一个空
        int i = s.size()-1, j = s.size()-1, insert_flag = 0;
        while (j>=0) {
            while (i >=0&&s[i] == ' ') i--;
            j = i;
            while (j >=0&&s[j] != ' ') j--;
            if(i==-1&&s[0]==' '){break;}
            // 单词[j+1,i+1)
            // cout << "i="<<i<<" j="<<j<<endl;
            if (insert_flag == 1) { ss << " "; }
            ss << s.substr(j+1, i-j);
            insert_flag = 1;
            i=j;
        }
        return ss.str();
    }
};