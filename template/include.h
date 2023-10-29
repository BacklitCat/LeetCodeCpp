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

int main_() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}

// get_input_to_vector
// 获取当前输入到vector<int>里
// 输入的第一个数字为vector长度
vector<int> get_input_to_vector_int(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    return vec;
}

// print_vector
// 打印vector<int>，入参为打印长度，超出部分打印 None
// 如果n<=0则为全打印
void print_vector(vector<int> nums, int n) {
    int i = 0, print_len = nums.size();
    if (n > 0) {
        print_len = min(int(nums.size()), n);
    }
    cout << "[ ";
    while (i < print_len) {
        cout << nums[i] << " ";
        i++;
    }
    cout << "]";
    while (i < n) {
        cout << " None";
        i++;
    }
    cout << endl;
}