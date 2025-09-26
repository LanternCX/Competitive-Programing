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
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2);
        return (res * res);
    }else{
        ll res = binpow(a, b - 1);
        return a * res;
    }
}
void sol(){
ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    for (int n = 0; n < 40; n++) {
        ll p = binpow(k, n);
        if (p > r2) {
            break;
        }
 
        auto chk = [&](ll x) {
            ll v = p * x;
            if (v < l2) {
                return -1;
            }
            if (v > r2) {
                return 1;
            }
            return 0;
        };

        ll L = r1 + 1;
        {
            ll l = l1, r = r1;
            while (l <= r) {
                ll mid = l + (r - l) / 2;
                if (chk(mid) >= 0) {
                    L = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
 
        ll R = l1 - 1;
        {
            ll l = l1, r = r1;
            while (l <= r) {
                ll mid = l + (r - l) / 2;
                if (chk(mid) <= 0) {
                    R = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
 
        if (L <= R) {
            ans += (R - L + 1);
        }
    }
 
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * y / x = k^n
 * 
 * 首先 y / x 可以用数论分块枚举
 * 时间复杂度 sqrt
 * 
 * 对于 k^n 增长很快
 * 可以直接枚举 k^n
 * 移项之后
 * y = k^n * x
 * 
 * 二分？
 * 好像并非
 * 
 * 相当于 y / x 有一个倍数关系
 * 然后直接在 l, r 里面组合数学
 * 
 * 好像不太对
 * 
 * 直接二分满足的左右端点
 * 然后就直接计数
 * 
 * 二分什么呢？
 * 二分每一个 x, 找到使得 y 落在 l2，r2 的左右端点
 * 答案就是二分得到的区间长度
 */