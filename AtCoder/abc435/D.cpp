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
void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
    }

    vector<int> b(n);

    auto dfs = [&](auto&& dfs, int v) -> void {
        debug (v);
        b[v] = 1;
        for (auto x : g[v]) {
            if (b[x]) {
                continue;
            }
            dfs(dfs, x);
        }
    };
    
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            x--;
            debug (op, x);
            if (b[x] != 1) {
                dfs(dfs, x);
            }
        }
        if (op == 2) {
            int x;
            cin >> x;
            x--;
            debug (op, x);
            cout << (b[x] ? "Yes" : "No") << '\n';
        }
    }
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