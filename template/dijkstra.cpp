#include "dijkstra.h"

/*
input n个节点 m条边
 6 10
 0 1 1
 0 2 3
 1 2 1
 1 3 4
 1 4 2
 2 3 5
 2 4 5
 3 5 3
 4 3 1
 4 5 6

 output
 0 1 2 4 3 7

 */
int main() {
    while (cin >> n >> m) {
        init(0);
        for (int i = 1; i <= m; ++i) {
            int from, to, val;
            cin >> from >> to >> val;
            add_edge(from, to, val);
        }
        dij(0);
        for (int i = 0; i < n; ++i) {
            cout << d[i] << " ";
        }
        puts("");
    }
}