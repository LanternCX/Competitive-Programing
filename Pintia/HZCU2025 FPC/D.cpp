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
    string s;
    cin >> s;
    map<int, int> cnt;
    for (auto ch : s) {
        cnt[ch]++;
    }
    double ans = cnt['2'] * 1.0 / (s.length() - cnt['-']);
    if (cnt['-']) {
        ans *= 1.5;
    }
    if (!((s[s.length() - 1] - '0') % 2)) {
        ans *= 2;
    }
    cout << ans * 100 << '%';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}