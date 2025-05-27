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
void sol(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (ll) a[i] + b[i]);
    }
    ll l = 0, r = mx;
    auto check = [&](int x) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                ll det = x - a[i];
                if (b[i] < det) {
                    return 0;
                }
                sum += x - a[i]; 
            }
        }
        if (sum > m) {
            return 0;
        }
        return 1;
    };
    int ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int chk = check(mid);
        if (chk) {
            ans = l;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << (l + r) / 2 << '\n';
}
int main(){
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
 * 贪心，二分？
 * 
 * 首先不考虑手写的情况那么组成卡牌的最小套数就是 min(a)
 * 
 * 二分什么呢？
 * 直接二分答案
 * 如何实现 check?
 * 
 * 对于一个答案 x, 代表着 min(a) = x
 * 所以大于 x 不需要书写
 * 只需要书写 小于 min(a) 的卡牌
 * 然后按照题意判断是否可行
 * 
 * 复杂度 nlogn
 */