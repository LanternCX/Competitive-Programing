#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct node {
    int x, w;
};

using pii = pair<int, int>;

void sol() {
    int n;
    cin >> n;
    vector<vector<node>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, w;
        cin >> x >> w;
        g[x].push_back({i + 1, w});
    }

    vector<pii> ans;
    auto dfs = [&](auto && dfs, int mn, int id) -> void {
        if (g[id].size() == 0) {
            ans.push_back({mn, id});
            return;
        }
        for (auto [x, w] : g[id]) {
            dfs(dfs, min(mn, w), x);
        }
    };
    // for (auto [x, w] : g[0]) {
    //     cout << x << '\n';
    // }
    dfs(dfs, INT_MAX, 0);

    int mx = 0;
    for (auto [mn, id] : ans) {
        mx = max(mn, mx);
    }

    cout << mx << '\n';
    vector<int> temp;
    for (auto [mn, id] : ans) {
        if (mn == mx) {
            temp.push_back(id);
        }
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " \n"[i == temp.size() - 1];
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