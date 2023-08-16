#include "heap_sort.h"

using namespace std;

int main() {
    vector<int> nums{1, 7, 1, 4, 5, 4, 6, 6, 7};
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;

    sort_ascending(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;

    sort_descending(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
}