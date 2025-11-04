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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector<vector<int>> pre(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        pre[0][i] = pre[0][i - 1];
        pre[1][i] = pre[1][i - 1];
        pre[s[i - 1] - 'a'][i]++;
    }

    ll ans = 0;
    int ar = 0, br = 0;
    for (int l = 1; l <= n; l++) {
        while (pre[0][ar] < pre[0][l - 1] + a && ar <= n) {
            ar++;
        }
        while (pre[1][br] < pre[1][l - 1] + b && br <= n) {
            br++;
        }
        ans += max(br - ar, 0);
    }
    cout << ans << "\n";
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
 * 前缀和？
 * 滑动窗口？
 *
 * r++ 使得 cnta 可以增加到 a
 * l++ 使得 cntb 可以减少到 b
 * abbaaabaaba
 *
 * 好像不对
 *
 * 前缀和之后
 * 二分
 *
 * 对于每一个 l
 * 可以二分得到 r
 * 这个 r 满足 条件 a 和条件 b
 * 不对
 * 应该是得到两个 ar, br
 * 然后同时满足 ar && br 的区间就是答案
 */