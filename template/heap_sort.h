#include <vector>
#include <iostream> // stringstream
#include <algorithm> //sort
#include <string> //stoi,memset
#include <unordered_map>
#include <unordered_set>
#include <cstdlib> // rand
#include <queue> // queue,priority_queue

using namespace std;

void max_heapify(vector<int> &nums, int heapsize, int root) {
//    cout << "max_heapify " << root<<endl;
    int l = root * 2+1, loc = root;
    int r = l + 1;
    if (l < heapsize && nums[l] > nums[root]) {
        loc = l;
        swap(nums[loc], nums[root]);
    }
    if (r < heapsize && nums[r] > nums[root]) {
        loc = r;
        swap(nums[loc], nums[root]);
    }
    if (loc != root) {
        max_heapify(nums, heapsize, loc);
    }
}

void build_max_heap(vector<int> &nums, int heapsize) {
    for (int i = (heapsize - 2) / 2; i >= 0; i--) {
        max_heapify(nums, heapsize, i);
    }
}

void sort_ascending(vector<int> &nums){
    int heapsize = nums.size();
    build_max_heap(nums, heapsize);

//    for(auto num : nums){
//        cout<<num<<" ";
//    }cout<<endl;

    for(int i=0;i< nums.size();i++){
        swap(nums[0],nums[nums.size()-i-1]);
        heapsize--;
        max_heapify(nums,heapsize,0);
    }
}

void min_heapify(vector<int> &nums, int heapsize, int root) {
//    cout << "max_heapify " << root<<endl;
    int l = root * 2+1, loc = root;
    int r = l + 1;
    if (l < heapsize && nums[l] < nums[root]) {
        loc = l;
        swap(nums[loc], nums[root]);
    }
    if (r < heapsize && nums[r] < nums[root]) {
        loc = r;
        swap(nums[loc], nums[root]);
    }
    if (loc != root) {
        min_heapify(nums, heapsize, loc);
    }
}

void build_min_heap(vector<int> &nums, int heapsize) {
    for (int i = (heapsize - 2) / 2; i >= 0; i--) {
        min_heapify(nums, heapsize, i);
    }
}

void sort_descending(vector<int> &nums){
    int heapsize = nums.size();
    build_min_heap(nums, heapsize);

    for(int i=0;i< nums.size();i++){
        swap(nums[0],nums[nums.size()-i-1]);
        heapsize--;
        min_heapify(nums,heapsize,0);
    }
}