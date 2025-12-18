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
    int n, m;
    cin >> n >> m;
    set<pii> s;
    int ans;
    while (m--) {
        int r, c;
        cin >> r >> c;
        int tag = 0;
        debug(r, c);
        for (int dx = 0; dx <= 1; dx++) {
            for (int dy = 0; dy <= 1; dy++) {
                int x = r + dx;
                int y = c + dy;
                if (s.count(pii(x, y))) {
                    debug(x, y);
                    tag = 1;
                    break;
                }
            }
            if (tag) {
                break;
            }
        }
        if (tag) {
            continue;
        }
        // debug(r, c);
        for (int dx = 0; dx <= 1; dx++) {
            for (int dy = 0; dy <= 1; dy++) {
                int x = r + dx;
                int y = c + dy;
                s.insert(pii(x, y));
            }
        }
        ans++;
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