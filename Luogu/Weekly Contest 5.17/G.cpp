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
struct LCA{
    int LOG;
    vector<vector<int>> fa;
    vector<int> dep;
    vector<vector<int>> g;

    LCA(vector<vector<int>> g): g(g), LOG(log2(g.size()) + 1){
        int n = g.size();
        fa = vector<vector<int>>(n, vector<int>(LOG, -1));
        dep = vector<int>(n);
        dfs(0, -1);
    }

    void dfs(int node, int from){
        fa[node][0] = from;
        for(int i = 1; i < LOG; i++){
            if(fa[node][i - 1] != -1){
                fa[node][i] = fa[fa[node][i - 1]][i - 1];
            }
        }
        for(auto next : g[node]){
            if(next == from){
                continue;
            }
            dep[next] = dep[node] + 1;
            dfs(next, node);
        }
    }

    int query(int u, int v){
        if(dep[u] < dep[v]){
            swap(u, v);
        }

        for(int i = LOG - 1; i >= 0; i--){
            if(dep[u] - (1 << i) >= dep[v]){
                u = fa[u][i];
            }
        }

        if(u == v){
            return u;
        }

        for(int i = LOG - 1; i >= 0; i--){
            if(fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
};
struct node {
    int id, d;
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> w(n);
    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        w[i] = g[i].size();
        sum[i] = w[i];
    }
    vector<int> vis(n);
    auto dfs = [&](auto &&dfs, int now) -> void {
        vis[now] = 1;
        for(auto x : g[now]){
            if (vis[x]) {
                continue;
            }
            sum[x] = sum[now] + w[x];
            dfs(dfs, x);
        }
        vis[now] = 0;
    };
    dfs(dfs, 0);
    debug(sum);
    LCA lca(g);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lc = lca.query(u, v);
        int ans = sum[u] + sum[v] - 2 * sum[lc] + w[lc];
        cout << ans << '\n';
    }
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
 * 写过
 * n - 1 条边是一颗树
 * u -> v
 * 这条路径上的答案就是所有的点权和
 * 
 * 直接跑最短路不太行
 * 树上的路径问题考虑求 LCA
 * 
 * 那么
 * 这条路径上的答案就是
 * u 到 rt 的答案
 * + v 到 rt 的答案
 * - 2 * lca 到 rt 的答案
 * 只需要 dfs 或者 bfs 一遍求出 rt 到每个节点的答案就行
 */