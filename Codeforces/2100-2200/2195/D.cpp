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
#define int long long
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n + 1);
    for (int i = 2; i <= n - 1; i++) {
        ans[i] = (a[i - 1] - 2 * a[i] + a[i + 1]) / 2;
    }
    
    ll sum = 0;
    for (int i = 2; i <= n - 1; i++) {
        sum += ans[i] * (i - 1);
    }
    ans[n] = (a[1] - sum) / (n - 1);

    sum = 0;
    for (int i = 2; i <= n - 1; i++) {
        sum += ans[i] * (n - i);
    }
    ans[1] = (a[n] - sum) / (n - 1);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * f[i + 1] - f[i] = sum(i, 1) + sum(i + 1, x)
 * (f[i + 1] - f[i]) - (f[i] - f[i - 1]) 
 * = sum(i, 1) + sum(i + 1, x) - (sum(1, i - 1) + sum(i, n))
 * = 2 * a[i]
 * 
 * a[i] = (f[i + 1] + f[i - 1] - 2 * f[i]) / 2
 * 
 * a[n] = 
 * a[1] = 
 * 直接模拟暴力
 */