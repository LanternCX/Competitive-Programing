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

    // dp[x] 表示以 x 为结尾的最长递增子序列的长度
    // dp[x] == dp[x - 1] + 1

    map<int, int> dp;

    for (auto x : a) {
        dp[x] = dp[x - 1] + 1;
    }

    int ans = 0;
    for (auto [x, i] : dp) {
        ans = max(i, ans);
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
/**
 * a[i] + 1 = a[i + 1]
 */