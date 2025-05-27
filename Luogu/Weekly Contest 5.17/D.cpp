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
struct edge {
    int u, w;
};
struct node {
    int id, dis;
    auto operator> (node nd)const {
        return dis > nd.dis;
    }
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    vector<vector<edge>> g(n);
    for (int i = 0; i < m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        if (u == 0) {
            g[u].push_back({v, w});
        } else {
            g[u].push_back({v, c[u] + w});
        }

        if (v == 0) {
            g[v].push_back({u, w});
        } else {
            g[v].push_back({u, c[v] + w});
        }
    }
    auto dij = [&](int st, vector<vector<edge>> g) {
        const int inf = INT_MAX;
        int n = g.size();
        vector<int> dist(n, inf);
        vector<int> vis(n, 0);
        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            if (vis[now.id]) {
                continue;
            }
            vis[now.id] = 1;
            for (auto &[u, w] : g[now.id]) {
                if (now.dis + w < dist[u]) {
                    dist[u] = now.dis + w;
                    pq.push({u, dist[u]});
                }
            }
        }
        return dist;
    };
    auto dist = dij(0, g);
    cout << dist[n - 1] << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 直接跑最短路
 * u 到 v 的边权实际上是 原边权 + u 的点权
 * v 到 u 同理
 */