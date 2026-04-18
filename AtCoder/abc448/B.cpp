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
    vector<int> c(m);
    vector<pii> arr(n);
    for (auto &x : c) {
        cin >> x;
    }

    map<int, ll> mp;

    for (auto &[a, b] : arr) {
        cin >> a >> b;
        mp[a - 1] += b;
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += min(mp[i], (ll) c[i]);
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