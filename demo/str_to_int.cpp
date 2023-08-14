#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string num_str;
    cin >> num_str;
    cout << num_str << endl;

    // stringstream
    // 不合法的输入会输出0
    int num;
    stringstream ss;
    ss << num_str;
    ss >> num;
    cout << "after ss: " << num << endl;

    // std stoi
    // 不合法的输入会有运行时错误
    cout << "after stoi: " << stoi(num_str) << endl;
}