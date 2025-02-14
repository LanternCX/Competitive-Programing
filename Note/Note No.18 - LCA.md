# ACM Note No.18: LCA

最近公共祖先(LCA，Lowest Common Ancestor (LCA))，是经典的树上问题。因为在树上两个点之前有且仅有一条路径联通，因此求出两个节点的LCA，知道了路径的拐点之后，就可以解决很多树上的路径问题。

LCA的最经典求法是使用倍增法求解，下面是一个求解LCA的模板。

我们知道，对于最近公共祖先这样的“求最问题”，使用二分答案进行时间复杂度优化是一个常见的技巧。而倍增法（Binary Lifting）求解LCA就运用了类似这样的技巧。

先设想一种朴素的算法：对于节点`u, v`查询他们的最近公共祖先，可以使用两个指针分别指向`u, v`。首先先**将两个指针深度对齐**，然后将两个指针**同时向上移动**。两个指针**第一次相遇的节点**就是节点`u, v`的最近共同祖先。

显然，对于这种线性的过程，使用二分进行优化是一个不错的选择。而倍增法的原理就是将指针向上移动的距离进行二分，将深度对齐和同时向上移动两个过程用二分法优化，从而降低时间复杂度。只不过相比于传统的二分，倍增法的二分更近一步：将二分和查询分离开来，也就是预处理二分过程中可能经过的点，在查询的时候直接按照预处理的信息进行访问。动画：[BV18B66Y6E3T](https://www.bilibili.com/video/BV18B66Y6E3T/)

倍增法求解LCA问题，预处理时间复杂度为`O(nlogn)`每次查询时间复杂度为`O(logn)`

似乎依旧有些抽象。让我们看看实现：

```c++
struct LCA{
    // 节点数量 n 的 log2(n) + 1 值
    int LOG;
    // fa[node][i] 表示 node 向上的第 2^i 个祖先节点的编号
    vector<vector<int>> fa;
    // dep[node] 表示 node 节点的深度
    vector<int> dep;
    // 树的邻接表存储
    vector<vector<int>> g;
    
    // 初始化
    LCA(vector<vector<int>> g, int root): g(g), LOG(log2(g.size()) + 1){
        int n = g.size();
        // fa 初始化为 -1 表示还没有经过处理
        fa = vector<vector<int>>(n, vector<int>(LOG, -1));
        dep = vector<int>(n);
        dfs(root, -1);
    }
    
    // DFS 处理 node 节点, from 表示 node 的父亲节点
    void dfs(int node, int from){
        // 第一步：初始化 fa 数组
        fa[node][0] = from;
        for(int i = 1; i < LOG; i++){
            // 跳过已经处理的节点
            if(fa[node][i - 1] != -1){
                // fa[node][i] 表示 node 向上的第 2^i 个祖先节点
                // fa[node][i - 1] 表示 node 向上的第 2^(i - 1) 个祖先节点
                // fa[fa[node][i - 1]][i - 1] 表示 node 向上的第 2^(i - 1) 个祖先节点向上的第 2^(i - 1) 个祖先节点
                // 例如：表示 node 向上的第 8 个祖先节点就是 node 向上的第 4 个祖先节点再向上 4 个祖先节点。
                // 也就是这里将 2^i 拆分成了 2^(i - 1) + 2^(i - 1)
                fa[node][i] = fa[fa[node][i - 1]][i - 1];
            }
        }
        // 第二步：初始化 dep 数组并进行下一层 dfs
        for(auto next : g[node]){
            // 跳过 node 的父节点防止死循环
            if(next == from){
                continue;
            }
            // 计算 next 节点的深度
            dep[next] = dep[node] + 1;
            dfs(next, node);
        }
    }
    
    // 查询节点 u 和节点 v 的最近公共祖先
    int query(int u, int v){
        // 保证 v 是深度较浅的节点
        if(dep[u] < dep[v]){
            swap(u, v);
        }
        
        // 第一步
        // 对齐 u 和 v 的深度
        // 由二分的性质，可以证明对于下面这样的跳转，第 n 次和第 n - 1 次跳转的距离是严格递减的，因此只需要 LOG 次循环
        for(int i = LOG - 1; i >= 0; i--){
            // dep[u] - (1 << i) 表示 u 向上跳转 i 次之后的深度，也就是跳转 2^i 层之后的深度
            if(dep[u] - (1 << i) >= dep[v]){
                // 一旦 u 跳转之后的深度恰好深于或等于 v 就执行跳转
                u = fa[u][i];
            }
        }
        
        // 如果此时重合了说明已经找到节点
        if(u == v){
            return u;
        }
        
        // 第二步
        // 两个节点同时向上尝试跳转，直到他们不能再跳转，过程类似第一步
        // 下面这样的跳转最终结果是 u 和 v 的深度相同且他们距离他们的公共祖先只相差了 1 次 2^0 层的跳转
        for(int i = LOG - 1; i >= 0; i--){
            // 如果两个节点跳转 i 次之后不重合，就进行跳转
            if(fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        // 最后直接返回 u 向上跳转 2^0 层的节点的编号
        return fa[u][0];
    }
};
```

### 例题

[Luogu P8805 蓝桥杯 2022 国B 机房](https://www.luogu.com.cn/problem/P8805)

这题显然是问我们从`u`节点走到`v`节点的最小代价。注意到给定的图是一颗树，那么`u`节点走到`v`节点的路径唯一，我们只需要找到这个路径并计算代价就行。

显然，`u 走到 v 的代价 = root 走到 v 的代价 + root 走到 u 的代价 - 2 * root 走到 u 和 v 的 LCA 的代价`，所以我们只需要求出`u 和 v 的LCA`就好

由于原来的图没有给我们 `root` 节点的编号，我们可以设 `root` 节点的编号为`0`，结果是一样的

```c++
#include <bits/stdc++.h>
using namespace std;
// LCA template
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> w(n), sum(n);
    for(int i = 0; i < n; i++){
        w[i] = g[i].size();
        sum[i] = w[i];
    }
    // DFS 计算 root 走到每一个节点的代价
    auto dfs = [&](auto&& dfs, int node, int fa) -> void {
        debug(node);
        for(auto next : g[node]){
            if(next == fa){
                continue;
            }
            sum[next] = sum[node] + w[next];
            dfs(dfs, next, node);
        }
    };
    dfs(dfs, 0, -1);
    LCA lca(g, 0);
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << sum[u] + sum[v] - 2 * sum[lca.query(u, v)] + w[lca.query(u, v)] << '\n';
    }
}
```

