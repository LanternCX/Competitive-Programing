# ACM Note No.13: Floyd 

**Floyd 算法**可用于求解非负权图上的多源最短路径，在非负权图跑一遍 Floyd 就可以知道该所有点到其他所有点的最短路径

Floyd 算法的核心思想是动态规划：

`i`节点到`j`节点的最短路径取决于 [`i`节点经过`k`节点到达`j`节点] 和 [不经过经过`k`节点到达`j`节点] 这两条路径之中的最短路

- 状态转移方程为`g[k][i][j] = min(g[k - 1][i][j], g[k - 1][i][k] + g[k - 1][k][j])`

- 可以优化为二维：`g[i][j] = min(g[i][j], g[i][k] + g[k][j])`

Floyd 算法复杂度为`O(N^3)`，对比直接对每个节点跑 Dijkstra算法的好处在于实现简单，具体实现参照代码

```c++
/**
* @param g 图的邻接矩阵
*/
void floyd(vector<vector<int>> &g){
    int n = g.size();
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (g[i][k] != inf && g[k][j] != inf) {
                    // 状态转移
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
}
```