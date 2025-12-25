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
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    ll ans = sum;
    auto calc = [&](int idx) {
        int l = 0, r = 0;
        int add = 0;
        if (idx > 0) {
            l = abs(a[idx] - a[idx - 1]);
        }
        if (idx < n - 1) {
            r = abs(a[idx + 1] - a[idx]);
        }
        if (idx > 0 && idx < n - 1) {
            add = abs(a[idx + 1] - a[idx - 1]);
        }
        return sum - l - r + add;
    };
    for (int i = 0; i < n; i++) {
        ans = min(ans, calc(i));
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