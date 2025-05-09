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
    ll v, w;
    cin >> v >> w;
    ll x = w / 2 + 1;
    ll ans = v / x;
    if(w - x < v % x){
        ans++;
    }
    cout << max(ans, 1LL) << '\n';
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
 * 等于说把 v 分成若干分
 * 
 * 挑大于等于 x 的最小
 * 也就是说 必须尽量让 储值卡的金额小于 x
 * 
 * x < v
 * 
 * 那么 x 如何选取呢
 * 直接枚举
 * 
 * 每次消费 x 
 * 
 * 那么每张卡就能消费 w / x 次
 * 
 * 总共需要消费 v / x
 * 
 * 消费了 (v / x) / (w / x) 之后 
 * 还剩下 (v / x) % (w / x) 次 和 v % x 元
 * 
 * 还需要判断 w 消费 (v / x) % (w / x) 次 之后是否还能剩下 v % x 元继续消费
 */