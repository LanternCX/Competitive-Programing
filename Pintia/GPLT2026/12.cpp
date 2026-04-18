#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pii = pair<int, int>;

void sol() {
    int n, m;
    cin >> n >> m;
    // v, w
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
    }

    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [](pii a, pii b) {
            if (a.second == b.second) {
                return a.first < b.first;
            };
            return a.second > b.second;
        });
    }
    
    auto calc = [&](int st) {
        vector<int> ans;
        vector<int> vis(n);
        auto dfs = [&](auto&& dfs, int now) {
            ans.push_back(now);
            vis[now] = 1;

            pii next = {-1, -1};
            for (auto [v, w] : g[now]) {
                if (vis[v]) {
                    continue;
                } else {
                    next = {v, w};
                    break;
                }
            }

            if (next == pair<int, int>(-1, -1)) {
                return;
            } else {
                dfs(dfs, next.first);
            }
        };

        dfs(dfs, st);
        
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] + 1;
            if (i != ans.size() - 1) {
                cout << "->";
            } else {
                cout << '\n';
            }
        }
    };

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int st;
        cin >> st;
        st--;
        calc(st);
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