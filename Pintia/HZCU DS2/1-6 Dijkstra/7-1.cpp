#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int inf = INT_MAX;
struct edge {
    int v, w;
};
struct node {
    int dis, id;
    bool operator>(node a) const {
        return dis > a.dis;
    }
};
/**
 * @param st 初始节点编号
 * @param g 图的邻接表
 */
vector<int> dij(int st, vector<vector<edge>> g) {
    int n = g.size();
    // 记录 st 节点到 i 节点的最短路程 dist[i]
    vector<int> dist(n);
    // 记录节点是否已经被访问
    // [已访问节点] 指的是已经计算了 [从 st
    // 节点通过该节点到所有相邻节点的最短路程] 的节点
    vector<bool> vis(n);
    // 记录到达 v 节点的上一个节点，可以通过这个数组还原出 st
    // 节点到某一节点的最短路径
    vector<int> fa(n);
    // 堆优化，维护未访问节点中到 st 节点距离最短的节点
    priority_queue<node, vector<node>, greater<node>> pq;
    // 将 st 点到任意一点的距离初始化为无穷远
    fill(dist.begin(), dist.end(), inf);

    // 初始化
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty()) {
        // 取出未访问节点中到 st 节点距离最短的节点
        int now = pq.top().id;
        pq.pop();
        if (vis[now]) {
            continue;
        }

        // 访问节点 next 并将该节点标记为已访问
        vis[now] = 1;

        // 计算通过 [ st 节点到达节点 now 的最短路] 到达 [所有未访问节点的距离]
        // 如果距离比先前计算的小就进行更新
        for (auto nd : g[now]) {
            int v = nd.v;
            int w = nd.w;
            if (!vis[v] && dist[now] + w < dist[v]) {
                dist[v] = dist[now] + nd.w;
                // 将待访问节点更新进入优先队列
                pq.push({dist[v], v});
                // 更新到达 v 节点的上一个节点
                fa[v] = now;
            }
        }
    }
    return dist;
}

void sol() {
    int n, m, st, ed;
    cin >> n >> m >> st >> ed;
    st--, ed--;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    auto dist = dij(st, g);
    cout << dist[ed] << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}