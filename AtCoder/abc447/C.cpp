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
    string s, t;
    cin >> s >> t;

    auto erase = [&](string s) {
        string res;
        for (auto ch : s) {
            if (ch == 'A') {
                continue;
            }
            res.push_back(ch);
        }  
        return res;
    };
    if (erase(s) != erase(t)) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    int x = 0, y = 0;
    while (x != s.length() || y != t.length()) {
        vector<int> cnt(2, 0);
        while (s[x] == 'A' && x != s.length()) {
            x++;
            cnt[0]++;
        }
        while (t[y] == 'A' && y != t.length()) {
            y++;
            cnt[1]++;
        }
        debug(x, y);
        ans += abs(cnt[0] - cnt[1]);
        if (x != s.length()) x++;
        if (y != t.length()) y++;
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
/**
 * ABACA
 * ABACA
 * 
 * AAAWAZAAAABAAAU
 * WAAZABAAAAAUA
 */