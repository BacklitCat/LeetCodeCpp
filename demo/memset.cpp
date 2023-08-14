#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int arr[10];
    memset(arr, 0, sizeof arr);
    for (int x: arr) { cout << x << " "; } cout << endl;
    memset(arr, 0x3f, sizeof arr);
    for (int x: arr) { cout << x << " "; } cout << endl;
    cout << 0x3f3f3f3f+0x3f3f3f3f << endl; // 防止爆int
    memset(arr, 1, sizeof arr); // 不是1，而是16843009
    for (int x: arr) { cout << x << " "; } cout << endl;
}