#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void sol(){
    int n, x, y;
    cin >> n >> x >> y;
    auto work = [&](int q){
        if(q > n){
            return 0LL;
        }
        int len = n - q;
        int a = x + q;
        int b = y - q;
        int temp = a - len + 1;
        ll tot = 0;
        if(b >= len){
            tot += (a + 1) * len;
        }else{
            tot += (a + 1) * b;
            len -= b;
            temp = a - len + 1;
            if(temp <= 0){
                len = a;
                temp = 1;
            }
            tot += (temp + a) * len / 2;
        }
        return tot;
    };
    ll ans = 0;
    for(int i = 0; i <= y; i++){
        ans = max(work(i), ans);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 先磨刀肯定更好 
 * 问题就转换为先磨刀几次再攻击使得伤害最高
 * 
 * 直接枚举就好
 */