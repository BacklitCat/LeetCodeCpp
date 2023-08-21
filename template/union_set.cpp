
const int N = 1e5;

int fa[N]; // 并查集数组

// 初始化并查集函数
void init(int n) {
    for (int i = 0; i < n; i++) fa[i] = i; // 初始时每个元素都是自己的父节点
}
// 查找操作，返回x所在集合的代表元素
int find(int x) {
    return x == fa[x] ? x : (fa[x] = find(fa[x])); // 如果x是根节点，直接返回x，否则递归查找x的父节点，并进行路径压缩
}
// 合并操作，将x和y所在的集合合并为一个新的集合
void merge(int x, int y) {
    fa[find(x)] = find(y); // 将x所在集合的根节点的父节点指向y所在集合的根节点
}
