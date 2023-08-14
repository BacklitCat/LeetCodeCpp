#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

// 最多N个节点，2N个边
const int N = 1e5;

//d[N] 是一个数组，用于存储源点到各个顶点的最短距离，初始值为无穷大。在Dijkstra算法中，d[N] 会不断更新，直到找到最优解。
//v[N] 是一个数组，用于记录顶点是否已经访问过，初始值为0。在Dijkstra算法中，v[N] 会防止重复访问已经确定最短距离的顶点。
//head[N] 是一个数组，用于存储以每个顶点为起点的最后一条边的编号，初始值为-1。在链式的存储方式中，head[N] 可以快速找到每个顶点的邻接边。
//cnt_edge 是一个变量，用于记录边的个数，初始值为0。在链式的存储方式中，cnt_edge 可以作为边的编号，也可以作为边数组的索引。

int n, m, d[N], v[N], head[N], cnt_edge;

struct Edge {
    int to, val, next;
} edge[N * 2];

struct Node {
    int val, pos;
    friend bool operator < (Node a, Node b) {//优先队列，边权值小的先出队
        return a.val > b.val;
    }
};

priority_queue<Node> q;

void add_edge(int from, int to, int val) {
    edge[cnt_edge].to = to;
    edge[cnt_edge].val = val;
    edge[cnt_edge].next = head[from];
    head[from] = cnt_edge++;
}

void dij(int s) {
    q.push({0, s});
    while(!q.empty()) {
        struct Node top = q.top();
        q.pop();
        if(v[top.pos]) continue;
        v[top.pos] = 1;
        for(int i = head[top.pos]; i != -1; i = edge[i].next) {
            int to_val = top.val + edge[i].val;
            int to_pos = edge[i].to;
            if(d[to_pos] > to_val) {
                d[to_pos] = to_val;
                q.push({to_val, to_pos});
            }
        }
    }
}

void init(int s) {//s为源点
    for(int i = 0; i <= n; ++i)  {
        if(i != s) d[i] = INT_MAX;
    }
    while(!q.empty()) q.pop();
    memset(head, -1, sizeof(head));
    memset(v, 0, sizeof(v));
    cnt_edge = 0;
}
