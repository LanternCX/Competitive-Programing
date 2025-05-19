#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief 并查集封装
 */
struct DSU {
    /**
     * @brief fa 数组, 节点 x 的父亲节点为 fa[x]
     */
    vector<int> fa;

    /**
     * @brief 并查集大小
     */
    int n;

    /**
     * @brief 构造函数
     * @param size 并查集大小
     */
    DSU(int size): n(size), fa(size) {
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };

    /**
     * @brief 递归查找根节点并进行路径压缩
     * @param x 当前查询的节点下标
     */
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    /**
     * @brief 合并两个节点
     * @param x 需要合并的节点下标 x
     * @param y 需要合并的节点下标 y
     */
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    /**
     * @brief 查询两个节点是否属于同一集合
     * @param x 查询的第一个节点下标
     * @param y 查询的第二个节点下标
     */
    bool query(int x, int y) {
        return find(x) == find(y);
    }
};

/**
 * @brief 无向边结构体定义
 */
struct node {
    /**
     * @brief 连接的节点下标 x
     */
    int x;
    
    /**
     * @brief 连接的节点下标 y
     */
    int y;
    
    /**
     * @brief 边权
     */
    int w;
};

void sol() {
    // 题目给定的边的数量和节点数量
    int m, n;
    while (cin >> n >> m) {
        // 循环输入直到 (m == 0 && n == 0)
        if (m == 0 && n == 0) {
            return;
        }
        // 初始化边权和
        ll sum = 0;
        // 初始化无向边集合
        vector<node> a(m);
        // 读入节点数据并计算边权和
        for (auto &[x, y, w] : a) {
            cin >> x >> y >> w;
            sum += w;
        }

        // 初始化并查集
        DSU dsu(n);
        
        // 将节点按照边权从小到大排序方便贪心
        sort(a.begin(), a.end(), [&](node a, node b) {
            return a.w < b.w;
        });
        
        // 初始化当前最下生成树的边的数量
        int cnt = 0;
        ll ans = 0;
        for (auto [x, y, w] : a) {
            // 一颗树的边的数量为 节点数量 - 1, 利用这个性质可以判断贪心终点
            if (cnt == n - 1) {
                break;
            }

            // 如果两个节点已经联通则当前边的加入对最小生成树没有贡献，应该跳过
            if (dsu.query(x, y)) {
               continue; 
            }

            // 加入新的边并用并查集维护两个节点的连通性，也就是维护当前的最小生成树的状态
            dsu.merge(x, y);
            // 记录已经加入的边的数量
            cnt++;
            // 累加边权和
            ans += w;
        }
        // 按照题目要求打印答案
        cout << sum - ans << '\n';
    }
}

int main() {
    // 快读快写
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}