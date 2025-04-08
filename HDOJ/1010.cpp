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
    vector<vector<pii>> g(n + 1);
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({u, w});
        g[v].push_back({v, w});
    }
    vector<int> color(n + 1);
    auto bfs = [&](){
        queue<int> q;
        vector<bool> vis(n + 1, false);
        q.push(1);
        vis[1] = 1;
        color[1] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, w] : g[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    color[v] = color[u] ^ (w % 2);
                    q.push(v);
                }
            }
        }
    };
    ll c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) c0++;
        else c1++;
    }
    ll ans = (c0 * c0 * c0 + c1 * c1 * c1) / 3;
    cout << ans << '\n';
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