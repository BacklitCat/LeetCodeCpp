#include <vector>
#include <string>
#include <queue>
using namespace std;
const int N = 1e5;
int n_, m, d[N], visited[N], head[N], edge_idx;

struct Edge {
    int v, w, next;
} edge[N * 2];

struct Node {
    int idx; // 下标
    int min_dest; // 源点到达当前节点时，目前的最短路径

    friend bool operator<(Node a, Node b) {//优先队列，边权值小的先出队
        return a.min_dest > b.min_dest;
    }
};

priority_queue<Node> q;

void init(int s) {//s为源点
    for (int i = 0; i <= n_; ++i) {
        if (i != s) d[i] = 0x3f3f3f3f;
        else if(i==s) d[i] = 0;
    }
    while (!q.empty()) q.pop(); // 确保队列空，不反复执行不用此行
    memset(head, -1, sizeof head); // nullptr 用-1代替
    memset(visited, 0, sizeof visited); // 0 没有访问过
    edge_idx = 0;
}

void add_edge(int u, int v, int w) {
    edge[edge_idx].v = v;
    edge[edge_idx].w = w;
    edge[edge_idx].next = head[u]; // 更新当前边的next指针
    head[u] = edge_idx++; // head 指针指向新边
}

void dij(int s) {
    q.push({s, 0});
    while (!q.empty()) {
        // 从大根堆取堆顶
        Node top = q.top();
        q.pop();
        // 如果已经被访问过，则跳过，否则置访问标记为1
        if (visited[top.idx]) continue;
        visited[top.idx] = 1;
        // 开始 visit，即遍历每一个当前点的邻接点，更新最短路径
        int u = top.idx;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            // 注意：此时i是edge的遍历下标，不是节点的
            int v = edge[i].v, w = edge[i].w;
            int new_dest = d[u] + w; // 从s到v的新的路径长度
            int min_dest = d[v]; // 已知从s到v的目前最短路径
            if (new_dest < min_dest) { // 如果更短，则更新d数组
                d[v] = new_dest;
                q.push({v, new_dest}); // 将节点v加入队列，当前距离是必须的，每次要pop最小的
            }
        }
    }
}

// Mid 743 https://leetcode.cn/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        n_ = n;
        init(k-1);
        for (auto t:times){
            add_edge(t[0]-1,t[1]-1,t[2]);
        }
        dij(k-1);
        int res=0;
//        for(int i = 0; i<n; i++){
//            cout << d[i]<<" ";}

        for(int i = 0; i<n; i++){
            res = max(res,d[i]);
            if (res >= 0x3f3f3f3f){
                return -1;
            }
        }
        return res;
    }
};