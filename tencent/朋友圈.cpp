#include <iostream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// https://www.nowcoder.com/exam/test/72635374/detail?pid=30545524&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany%3FcurrentTab%3Drecommand%26jobId%3D100%26selectStatus%3D0%26tagIds%3D138&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91

// 有 bug 先放着

using namespace std;

// union 并查集
const int N = 1e5;
int father[N];

// user <user,count>
unordered_map<int, long> user_count;


void init() {
    memset(father, -1, sizeof father);
    user_count.clear();
}

// 查找u的根，顺带优化高度
int find(int u) {
    if (father[u] == -1) {
        father[u] = u;
        return u;
    }
    int fa = u;
    while (father[fa] != fa) {
        fa = father[fa];
    }
    father[u] = fa;
    return fa;
}

// 合并 u v 集合
void merge(int u, int v) {
    int u_fa = find(u);
    int v_fa = find(v);

    int u_user_count, v_user_count;

    if (user_count[u_fa] == 0) {
        u_user_count = 1;
    } else {
        u_user_count = user_count[u_fa];
        user_count.erase(u_fa); // 删除ufa
    }

    if (user_count[v_fa] == 0) {
        v_user_count = 1;
    } else {
        v_user_count = user_count[v_fa];
    }

    // 简化，把u并进v
    user_count[v_fa] = v_user_count + u_user_count;
    father[u_fa] = v_fa;
//    cout << "merge "<< u << " to " << v << "  user_count[u_fa]="<< user_count[u_fa]<<"  user_count[v_fa]=" << user_count[v_fa]<<endl;
}

long max_count() {
    long ret = 0;
    for (auto k: user_count) {
        ret = max(ret, k.second);
    }
    return ret;
}


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int T;
    long long n, x, y;
    cin >> T;
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            merge(x - 1, y - 1);
        }
        cout << max_count() << endl;
    }
}

/*
2
4
1 2
3 4
5 6
1 6
4
1 2
3 4
5 6
7 8
  */