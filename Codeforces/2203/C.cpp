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
#define int ll
void sol() {
    ll s, m;
    cin >> s >> m;
    
    ll ans = 0;
    for (int k = 1; k < 64; k++) {
        // 截断低 k 位

        ll sx = s & ((1ll << k) - 1);
        ll mx = m & ((1ll << k) - 1);

        if (mx == 0) {
            if (sx > 0) {
                cout << -1 << "\n";
                return;
            }
        } else {
            ans = max(ans, (sx + (mx - 1)) / mx);
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * 从大到小枚举 ai 的所有可能之后从 s 里面减掉？
 * 
 * 5 = 101, 5 4 1 0
 * 
 * 13: 5 5 1 1 
 * 好像不对
 * 
 * 13 1101
 * 5 101
 * 
 * 3 2
 * 11 10
 * 
 * 这种就是 -1
 * 
 * 也就是 s 的 低 k 位必须由 m 的低 k 位贡献 如果贡献不了就是 -1
 * 但是 s 的高于 k 位的部分也可以由 m 的低 k 位贡献
 * 如果一直能贡献那一定就有解？
 * 也就是说我们要关注低 k 位的值
 * 
 * 那就 m 的低 k 位先解决 s 的低 k 位 ？
 * 
 * 几乎是对的emm
 * 没开ll
 */