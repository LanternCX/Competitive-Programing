# ACM Note No.9: Graph

## 图的存储

图的存储方式有主要的两种：邻接表与邻接矩阵

- 邻接表：使用`vector<vector<node>>`存储，存储节点`i`的所有出边和权值
- 邻接矩阵：使用二维数组存储，`mp[i][j] = w`表示节点`i`到`j`有一条权值为`w`的边

### Luogu B3643

给定一个`n `个顶点`m`条边的无向图。以邻接矩阵和邻接表的形式输出这一张图

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> mp(n, vector<int>(n));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // 变换为 0 开头
        u--, v--;
        // 邻接表存储
        g[u].push_back(v);
        g[v].push_back(u);
        // 邻接矩阵
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    // 打印邻接矩阵
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    // 邻接表排序
    for(auto &arr : g){
        sort(arr.begin(), arr.end());
    }
    // 打印邻接表
    for(auto arr : g){
        cout << arr.size() << ' ';
        for(auto x : arr){
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
```

## 树

树是一个**无向无环图**

**边**：可以证明，一颗由`n`个节点的树有且仅有`n - 1`条边

**链**：与任意一个节点相连的边不超过两条的树：[NowCoder 95323/B](https://ac.nowcoder.com/acm/contest/95323/B)

