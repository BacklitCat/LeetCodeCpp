#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
    小美的树上染色
    https://www.nowcoder.com/exam/test/72408955/detail?pid=51799538&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany%3FcurrentTab%3Drecommand%26jobId%3D100%26selectStatus%3D0%26tagIds%3D179&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
 */
// 判断平方数
bool isQrt(int n) {
    int x = sqrt(n);
    return x * x == n;
}

const int N = 1e5 + 10;

// 该题目虽然是树，但是可以类比图

struct Node {
    int value; // 权值
    vector<int> children; // 存储子节点，避免讨论左右，可扩展为图
} node[N];

int dp[N][2]; // 树形dp，可以染色的最大数量，(不染，染)当前节点

void dfs(int root, int parent) {
    // 不染色
    for (auto child: node[root].children) {
        dfs(child, root);
        // root不染色，则最大dp值由子树dp值确定
        dp[root][0] += max(dp[child][0], dp[child][1]);
    }

    // 染色，这个循环不能合并
    for (auto child: node[root].children) {
        // 如果root和该child的积是完全平方数，且子节点没有染色，才能尝试染色
        // 每次尝试和没染色的且积是完全平方数尝试染色，如果child都染色了。则该节点无法染色
        if (isQrt(node[root].value * node[child].value)) {
            // 公式参考：https://zhuanlan.zhihu.com/p/649652679
            // 这里利用计算好的dp[root][0]，dp[root][0]里含有已经合起来的所有的值，就不用再循环计算或者累加了
            // dp[root][0] - max(dp[child][0], dp[child][1]) 减去了当前节点的未染色或者染色的贡献
            // 这样就可以计算，到当前节点时，其他节点不染色的贡献+dp[child][0] + 2
            dp[root][1] = max(dp[root][1], dp[root][0] - max(dp[child][0], dp[child][1]) + dp[child][0] + 2);
        }
    }
//    cout << "dfs root=" << root << " dp[0]=" << dp[root][0] << " dp[1]=" << dp[root][1] << endl;
}

int main() {
    int n; // 节点数量
    while (cin >> n) {
        int val, u, v;
        // 该题目下标从1开始
        // 赋权值，初始化
        for (int i = 1; i <= n; ++i) {
            cin >> val;
            node[i].value = val;
            node[i].children.clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        // 赋边 n-1 条
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            if (u > v) swap(u, v); // 确保u指向v
            node[u].children.push_back(v);
        }
        dfs(1, -1);
//        for (int k = 1; k <= n; k++) cout << k << " " << dp[k][0] << " " << dp[k][1] << endl;
        cout << max(dp[1][0], dp[1][1]);
    }
}

