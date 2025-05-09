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
    int v, w;
    cin >> v >> w;
    int ans = 0;
    for(int i = 1; i <= v; i++){
        if(w / i <= 0){
            continue;
        }
        int cnt = 0;
        cnt += (v / i) / (w / i);
        int m = (v / i) % (w / i);
        if(m){
            cnt += 1; 
        }
        if(w - m * i < v % i){
            cnt += 1;
        }
        ans = max(cnt, ans);
    }
    cout << ans << '\n';
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
 * 总共需要消费 v / x + 1
 * 
 * 消费了 (v / x) / (w / x) 之后 
 * 还剩下 (v / x) % (w / x) 次 和 v % x 元
 * 
 * 还需要判断 w 消费 (v / x) % (w / x) 次 之后是否还能剩下 v % x 元继续消费
 */