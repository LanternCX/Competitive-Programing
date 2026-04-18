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
    int n, L, R;
    cin >> n >> L >> R;
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]].push_back(i);
    }

    ll ans = 0;
    for (auto [_, idx] : mp) {
        debug(_, idx);
        for (auto x : idx) {
            // >= L
            // r >= x + L 
            auto l = lower_bound(idx.begin(), idx.end(), x + L);
            // r - x <= R
            // x + R >= r
            auto r = upper_bound(idx.begin(), idx.end(), x + R);
            debug(l - idx.begin(), r - idx.begin());
            ans += r - l;
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