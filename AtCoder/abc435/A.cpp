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
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i;
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