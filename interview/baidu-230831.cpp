#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int i, j;
    while (cin >> str) {
        i = 0;
        j = str.size() - 1;
        while (i<j){
            while (str[i] == '$') i++;
            while (str[j] == '$') j--;
            swap(str[i],str[j]);
            i++; j--;
        }
        cout << str;
    }
    return 0;
}