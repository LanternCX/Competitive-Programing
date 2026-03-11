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
const int mod = 1e9 + 7;
void sol() {
    int n;
    cin >> n;
    vector<pii> g(n + 1);
    for (int i = 1; i <= n; i++) cin >> g[i].first >> g[i].second;
    
    vector<ll> dp(n + 1), ans(n + 1);
    
    auto dfs1 = [&](auto&& dfs, int u) -> void {
        if (!g[u].first) {
            dp[u] = 1;
            return;
        }
        dfs(dfs, g[u].first);
        dfs(dfs, g[u].second);
        dp[u] = (dp[g[u].first] + dp[g[u].second] + 3) % mod;
    };

    dfs1(dfs1, 1);
    auto dfs2 = [&](auto&& dfs, int u, ll s) -> void {
        s = (s + dp[u]) % mod;
        ans[u] = s;
        if (g[u].first) {
            dfs(dfs, g[u].first, s);
            dfs(dfs, g[u].second, s);
        }
    };
    dfs2(dfs2, 1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}