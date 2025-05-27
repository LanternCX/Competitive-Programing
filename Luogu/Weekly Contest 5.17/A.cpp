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
#define int long long
void sol(){
    int n, Q;
    cin >> n >> Q;
    vector<int> r(n);
    for (auto &x : r) {
        cin >> x;
    }
    sort(r.begin(), r.end());
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[r[i]]++;
    }

    unordered_map<int, int> ans;
    int mx = r[n - 1];
    for (int i = 0; i < n; i++) {
        for (ll q = 0; q * r[i] <= mx; q++) {
            if (cnt[q * r[i]] >= 1) {
                ans[q] = 1;
            }
        }
    }
    while (Q--) {
        int q;
        cin >> q;
        if (ans[q]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 2e5
 * 
 * 首先 w2 : w1 = r1 : r2
 * 就是反过来的
 * 
 * 如果传递呢？
 * dp? 有点像背包
 * 
 * 线速度是一样的
 * 所以说实际上和中间件没有关系？
 * 
 * qw = w * (r1 / r2)
 * q = (r1 / r2)
 * 
 * 实际上是求是否存在 r1, r2 使得 r1 / r2 == q
 * 
 * Q 组询问
 * 直接二分？
 * q = r1 / r2
 * r1 = q * r2
 * 每次询问 nlogn
 * 30分 好像不对
 * 算了先写一个
 * 
 * 离线好像不对
 * 直接处理每次询问也不太对
 * 可以直接预处理出所有答案吗？
 * 
 * q = r1 / r2
 * 直接枚举 r2 
 * 检查每一个 q 判断 是否有 r1 能匹配上
 */