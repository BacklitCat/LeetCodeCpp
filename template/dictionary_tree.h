#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100000;
const int MAXM = 26;

// 树节点定义
struct DictTrieNode {
    int child[MAXM]; // 值存储孩子在数组中的位置
    int val; // 出现次数
};

// 为了避免频繁申请内存，一次申请够;0节点默认根节点
DictTrieNode trie[MAXN];
// 边界，记录节点数量；根节点不存储字符
int idx = 0;

// insert 给定字符串s，插入到字典树中
void dt_insert(string s) {
    int u = 0;
    // 遍历字符串s，逐步的去插入
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!trie[u].child[c]) {
            trie[u].child[c] = ++idx;
        }
        u = trie[u].child[c];
    }
    trie[u].val += 1;
}

// query 查询插入过的次数；0：未出现
int dt_query(string s) {
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!trie[u].child[c]) {
            return 0;
        }
        u = trie[u].child[c];
    }
    return trie[u].val;
}