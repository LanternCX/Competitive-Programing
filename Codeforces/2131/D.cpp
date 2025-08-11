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
void sol(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;

    }
    if (n == 2) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;

    // vector<int> vis(n);
    // auto dfs = [&](auto&& dfs, int idx, int d) -> void {
    //     vis[idx] = 1;
    //     int tag = 0;
    //     for (auto nd : g[idx]) {
    //         if (!vis[nd]) {
    //             dfs(dfs, nd, d + 1);
    //             tag = 1;
    //         }
    //     }
    //     if (tag == 0) {
    //         ans++;
    //         debug(idx, g[idx]);
    //     }
    // };
    // dfs(dfs, 0, 0);
    
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            ans++;
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int to : g[i]) {
            if (deg[to] == 1) {
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    cout << ans - mx << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}