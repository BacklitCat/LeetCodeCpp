#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

// 最多N个节点，2N个边
const int N = 1e5;

//d[N] 是一个数组，用于存储源点到各个顶点的最短距离，初始值为无穷大。在Dijkstra算法中，d[N] 会不断更新，直到找到最优解。
//visited[N] 是一个数组，用于记录顶点是否已经访问过，初始值为0。在Dijkstra算法中，visited[N] 会防止重复访问已经确定最短距离的顶点。
//head[N] 是一个数组，用于存储以每个顶点为起点的最后一条边的编号，初始值为-1。在链式邻接表的存储方式中，head[N] 可以快速找到每个顶点的邻接边。
//edge_idx 是一个变量，用于记录边的个数，初始值为0。在链式邻接表的存储方式中，edge_idx 可以作为边的编号，也可以作为边数组的索引。

int n, m, d[N], visited[N], head[N], edge_idx;

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

// add_edge 将从u到v的边，添加到链式邻接表，w是权重，dij要求w必须非负
void add_edge(int u, int v, int w) {
    edge[edge_idx].v = v;
    edge[edge_idx].w = w;
    edge[edge_idx].next = head[u]; // 更新当前边的next指针
    head[u] = edge_idx++; // head 指针指向新边
}

// dij 遍历；s:source 源点，从s开始遍历所有的点
void dij(int s) {
    q.push({0, s});
    while (!q.empty()) {
        // 从大根堆取堆顶
        Node top = q.top();
        q.pop();
        // 如果已经被访问过，则跳过，否则置访问标记为1
        if (visited[top.idx]) continue;
        visited[top.idx] = 1;
        // 开始 visit，即遍历每一个当前点的邻接点，更新最短路径
        for (int u = head[top.idx]; u != -1; u = edge[u].next) {
            int new_dest = d[top.idx] + edge[u].w; // 新的路径长度
            int min_dest = d[edge[u].v]; // 已知到v的目前最短路径
            if (new_dest < min_dest) { // 如果更短，则更新d数组
                d[edge[u].v] = new_dest;
                q.push({edge[u].v,new_dest});
            }
        }
    }
}

void init(int s) {//s为源点
    for (int i = 0; i <= n; ++i) {
        if (i != s) d[i] = 0x3f3f3f3f;
    }
    while (!q.empty()) q.pop(); // 确保队列空，不反复执行不用此行
    memset(head, -1, sizeof head); // nullptr 用-1代替
    memset(visited, 0, sizeof visited); // 0 没有访问过
    edge_idx = 0;
}
