#include "dijkstra.h"

int main() {

    while(cin>>n>>m) {
        init(0);
        for(int i = 1; i <= m; ++i) {
            int from, to, val;
            cin>>from>>to>>val;
            add_edge(from, to, val);
        }
        dij(0);
        for(int i = 0; i < n; ++i) {
            cout << d[i] << " ";
        }
        puts("");
    }
}