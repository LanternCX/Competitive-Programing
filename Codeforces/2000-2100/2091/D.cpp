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
    // int n, m, k;
    // cin >> n >> m >> k;
    // int mod = n % k;
    // k /= n;
    // int ans = ceil(m * 1.0 / k);
    // ans += mod == 0;
    ll n, m, k;
    cin >> n >> m >> k;
    ll x = (k + n - 1) / n;
    auto judge = [&](int mid){
        ll cnt = (x + mid - 1) / mid;
        return x + cnt - 1 <= m;
    };
    ll l = 1, r = x, ans = x;
    while(l <= r){
        ll mid = (l + r) / 2;
        debug(l, r);
        if(judge(mid)){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
void sol2(){
    int n, m, k;
    cin >> n >> m >> k;
    
    int x = (k + n - 1) / n;
    
    cout <<  m / (m - x + 1) << "\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol2();
    }
    return 0;
}