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
    int l, a, b;
    cin >> l >> a >> b;
    vector<int> vis(l);
    int ans = 0;
    for (int i = 0; i < 1e5; i++) {
        a = (a + b) % l;
        if (!vis[a]) {
            ans = max(a, ans);
            vis[a] = 1;
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