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
    vector<vector<int>> up; 
    vector<int> d;
    vector<vector<int>> g;

    LCA(vector<vector<int>> g): g(g), LOG(log2(g.size()) + 1){
        int n = g.size();
        up = vector<vector<int>>(n, vector<int>(LOG, -1));
        d = vector<int>(n);
        dfs(0, -1);
    }

    void dfs(int node, int fa){
        up[node][0] = fa;
        for(int i = 1; i < LOG; i++){
            if(up[node][i - 1] != -1){
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
        }
        for(auto next : g[node]){
            if(next == fa){
                continue;
            }
            d[next] = d[node] + 1;
            dfs(next, node);
        }
    }

    int query(int u, int  v){
        if(d[u] < d[v]){
            swap(u, v);
        }

        for(int i =  LOG - 1; i >= 0; i--){
            if(d[u] - (1 << i) >= d[v]){
                u = up[u][i];
            }
        }
        
        if(u == v){
            return u;
        }

        for(int i = LOG - 1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
void sol(){
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
    LCA lca(g);
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << sum[u] + sum[v] - 2 * sum[lca.query(u, v)] + w[lca.query(u, v)] << '\n';
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