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
const ll inf = LLONG_MAX;
void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int k;
    cin >> k;
    vector<int> p(k);
    for (auto &x : p) {
        cin >> x;
        x--;
    }

    p.push_back(n - 1);
    sort(p.begin(), p.end());

    vector<vector<int>> b;
    int idx = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
        if (i == p[idx]) {
            idx++;
            b.push_back(temp);
            temp.clear();
        }
    }
    
    // dp[i][j] 从第一层的任意一个数字出发
    // 逐层向下，在第 i 层的第 j 个数字上时
    // 所积累的最小绝对值差之和
    vector<vector<ll>> dp(b.size());
    for (int i = 0; i < b.size(); i++) {
        dp[i].assign(b[i].size(), inf);
    }

    // 初始化第一层代价为 0
    for (int j = 0; j < dp[0].size(); j++) {
        dp[0][j] = 0;
    }

    // 状态转移
    for (int i = 1; i < b.size(); i++) {
        for (int j = 0; j < b[i].size(); j++) {
            for (int u = 0; u < b[i - 1].size(); u++) {
                ll cost = dp[i - 1][u] + abs(b[i][j] - b[i - 1][u]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    ll ans = inf;
    for (ll val : dp.back()) {
        ans = min(ans, val);
    }

    cout << ans << '\n';
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