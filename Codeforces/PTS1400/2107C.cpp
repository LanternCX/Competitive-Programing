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

const ll inf = 1e13;
void sol(){
    int n; 
    long long k; 
    cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            idx = i;
            a[i] = -inf;
        }
    }

    // dp[i] 表示以 i 结尾的最大子段和
    vector<ll> dp(n);
    dp[0] = a[0];
    ll mx = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        mx = max(mx, dp[i]);
    }

    if (mx > k || (mx != k && idx == -1)) {
        cout << "No\n";
        return;
    }

    if (idx != -1) {
        ll l = 0, r = 0;
        ll sum = 0;
        for (int i = idx + 1; i < n; i++) {
            sum += a[i];
            l = max(l, sum);
        }

        sum = 0;
        for (int i = idx - 1; i >= 0; i--) {
            sum += a[i];
            r = max(r, sum);
        }

        a[idx] = k - l - r;
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i + 1 == n];
    }
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