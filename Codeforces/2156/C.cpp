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
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    map<int, int> cnt;
    for (int x : a) {
        cnt[x]++;
    }
    vector<int> pre(mx + 5);
    for (int i = 1; i <= mx; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    int ans = 1;
    for (int g = 1; g <= mx; g++) {
        int up = min(mx, 4 * g - 1);
        int tot = pre[up];
        int sp = 0;
        for (int m = g; m <= up; m += g) {
            sp += cnt[m];
        }
        int need = tot - sp;
        if (need <= k) {
            ans = max(ans, g);
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
/**
 * 二分？
 * 对于每一个 g
 * 贪心的想
 * 就应该是 先 split 再 erase
 * split 条件应该是 x1 = g x2 = g + x % g x3 = g - (x1 + x2) 至少 g * 2
 * 因此就是 4 * g 
 * 实在不行就 erase
 * 
 * emm 样例好像错一个
 * 
 * 好像不用二分？
 * 通过类似前缀和的方法
 * 
 * 然后我们也可以直接统计
 */
