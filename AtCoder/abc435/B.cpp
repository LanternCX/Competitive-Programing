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
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            ll sum = 0;
            for (int i = l; i <= r; i++) {
                sum += a[i];
            }
            int tag = 0;
            for (int i = l; i <= r; i++) {
                if (sum % a[i] == 0) {
                    tag = 1;
                    break;
                }
            }
            if (!tag) {
                ans++;
            }
        }
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