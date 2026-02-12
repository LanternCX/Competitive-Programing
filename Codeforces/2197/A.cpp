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
    ll n;
    cin >> n;
    auto calc = [&](ll x) {
        string s = to_string(x);
        int sum = 0;
        for (auto ch : s) {
            sum += ch - '0';
        }
        return sum;
    };
    int ans = 0;
    for (ll i = n; i <= n + 100; i++) {
        if (i - calc(i) == n) {
            ans++;
        }
    }
    cout << ans << '\n';
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
/**
 * 1 - 10
 * 10 - 1 9
 * 11 - 2 9
 * 100 - 1
 * 200 - 1
 */