#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1e4; // 字符串最大长度
int n; // 字符串长度
string s; // 字符串

// 获取n的所有约数的函数
vector<int> get_divisors(int n) {
    vector<int> res; // 存储结果
    for (int i = 1; i <= n / i; i++) { // 遍历从1到n的平方根
        if (n % i == 0) { // 如果i是n的约数
            res.push_back(i); // 把i加入结果
            if (i != n / i) res.push_back(n / i); // 如果i不等于n/i，把n/i也加入结果
        }
    }
    sort(res.begin(), res.end()); // 对结果排序
    return res; // 返回结果
}

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

// 计算并查集的根节点个数
int count_fa(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) { count++; }
    }
    return count;
}

int d[4][2] = {{-1, 0},
               {1,  0},
               {0,  -1},
               {0,  1}};

// 计算权值函数, a,b为现在的列,行数
int get_weight(int a, int b) {
    int n = a * b;
    int x, y, nx, ny;
    init(n);
    for (int i = 0; i < n; i++) {
        x = i / a;
        y = i % a;
        for (int j = 0; j < 4; j++) {
            nx = x + d[j][0];
            ny = y + d[j][1];
            if ((nx >= 0 && nx < b) && (ny >= 0 && ny < a)) { // 这里卡了很久 矩阵一定要小心行列关系
                int loc = nx * a + ny; // 还原字符串实际位置
                cout << "(" << x << "," << y << ")->(" << nx << "," << ny << ") i:" << i << " loc:"<<loc << endl;
                if (i != loc && s[i] == s[loc]) {
                    cout <<"merge:"<<s[i]<<endl;
                    merge(loc, i);
                }
            }
        }
    }
    return count_fa(n); // 返回权值
}

int main() {
    while (cin >> n) { // 输入字符串长度
        if (n == 1) { // 处理n为1的情况
            cout << 1 << endl;
            continue;
        }
        cin >> s; // 输入字符串
        vector<int> divs = get_divisors(n); // 获取n的所有约数
        int ans = n; // 答案初始化为n，因为最坏情况下每个字符都是一个连通块
        for (int x: divs) { // 枚举所有可能的列数
            int y = n / x;
            cout <<"x="<<x<<" y="<<y<<endl;
            ans = min(ans, get_weight(x, y));
        cout << "ans="<<ans<<" x="<<x<<" y="<<y <<endl;
        }
        cout << ans << endl; // 输出答案
    }
    return 0;
}
