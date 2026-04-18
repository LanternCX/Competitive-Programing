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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    set<int> s;
    map<int, int> cnt;
    vector<int> path, ans(n, 1), vis(n);
    auto dfs = [&](auto&& dfs, int nd, int fa) -> void {
        s.insert(a[nd]);
        path.push_back(a[nd]);
        cnt[a[nd]]++;

        debug(nd, s, path);

        vis[nd] = 1;
        if (s.size() == path.size()) {
            ans[nd] = 0;
        }
        for (auto x : g[nd]) {
            if (vis[x]) continue;
            dfs(dfs, x, nd);
        }
        
        path.pop_back();
        if (cnt[a[nd]] == 1) {
            s.erase(a[nd]);
        }
        cnt[a[nd]]--;
    };

    dfs(dfs, 0, -1);

    for (auto x : ans) {
        cout << (x ? "Yes" : "No") << '\n';
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