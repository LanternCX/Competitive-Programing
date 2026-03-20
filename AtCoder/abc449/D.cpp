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
    int L, R, D, U;
    cin >> L >> R >> D >> U;
    ll ans = 0;
    // l r : black
    auto calc = [&](int l,int r, int LX, int RX) {
        // debug(l, r, LX, RX);
        assert(l <= r && LX <= RX);
        if (l > RX || r < LX) {
            return 0;
        }
        int lx = max(l, LX);
        int rx = min(r, RX);
        int res = rx - lx + 1;
        debug(res);
        assert(res > 0);
        return res;
    };
    for (int i = 2; i <= 1e6; i += 2) {
        int d = -i;
        int u = i;
        int l = -i;
        int r = i;
        // lu ru
        if (u >= D && u <= U) {
            ans += calc(l, r, L, R);
        }
        // ld rd
        if (d >= D && d <= U) {
            ans += calc(l, r, L, R);
        }
        // lu ld
        if (l >= L && l <= R) {
            ans += calc(d, u, D, U);
        }
        // ru rd
        if (r >= L && r <= R) {
            ans += calc(d, u, D, U);
        }

        // l
        if (l >= L && l <= R) {
            // lu
            if (u <= U && u >= D) {
                ans -= 1;
            }
            // ld
            if (d <= U && d >= D) {
                ans -= 1;
            }
        }

        // r
        if (r >= L && r <= R) {
            // ru
            if (u <= U && u >= D) {
                ans -= 1;
            }
            // rd
            if (d <= U && d >= D) {
                ans -= 1;
            }
        }
    }
    if (0 >= L && 0 <= R && 0 <= U && 0 >= D) {
        ans += 1;
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