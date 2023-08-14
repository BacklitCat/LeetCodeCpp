#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

// 最多N个节点，2N个边
const int N = 1e5;

//d[N] 是一个数组，用于存储源点到各个顶点的最短距离，初始值为无穷大。在Dijkstra算法中，d[N] 会不断更新，直到找到最优解。
//visited[N] 是一个数组，用于记录顶点是否已经访问过，初始值为0。在Dijkstra算法中，visited[N] 会防止重复访问已经确定最短距离的顶点。
//head[N] 是一个数组，用于存储以每个顶点为起点的最后一条边的编号，初始值为-1。在链式邻接表的存储方式中，head[N] 可以快速找到每个顶点的邻接边。
//cnt_edge 是一个变量，用于记录边的个数，初始值为0。在链式邻接表的存储方式中，cnt_edge 可以作为边的编号，也可以作为边数组的索引。

int n, m, d[N], visited[N], head[N], cnt_edge;

struct Edge {
    int v, w, next;
} edge[N * 2];

struct Node {
    int val, pos;
    friend bool operator < (Node a, Node b) {//优先队列，边权值小的先出队
        return a.val > b.val;
    }
};

priority_queue<Node> q;

void add_edge(int u, int v, int w) {
    edge[cnt_edge].v = v;
    edge[cnt_edge].w = w;
    edge[cnt_edge].next = head[u]; // 更新当前边的next指针
    head[u] = cnt_edge++; // head 指针指向新边
}

void dij(int s) {
    q.push({0, s});
    while(!q.empty()) {
        struct Node top = q.top();
        q.pop();
        if(visited[top.pos]) continue;
        visited[top.pos] = 1;
        for(int i = head[top.pos]; i != -1; i = edge[i].next) {
            int to_val = top.val + edge[i].w;
            int to_pos = edge[i].v;
            if(d[to_pos] > to_val) {
                d[to_pos] = to_val;
                q.push({to_val, to_pos});
            }
        }
    }
}

void init(int s) {//s为源点
    for(int i = 0; i <= n; ++i)  {
        if(i != s) d[i] = 0x3f3f3f3f;
    }
    while(!q.empty()) q.pop(); // 确保队列空，不反复执行不用此行
    memset(head, -1, sizeof head);
    memset(visited, 0, sizeof visited);
    cnt_edge = 0;
}
