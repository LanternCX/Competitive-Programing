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
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i-1];
    }
    ll sum = pre[n];
    ll tot = k * sum;
    
    if(tot < x){
        cout << 0 << "\n";
        return;
    }
    
    ll ans = 0;
    for (int r = 0; r < n; r++){
        if(tot - x < pre[r]) {
            continue;
        }
        ll mx = (tot - x - pre[r]) / sum;
        ll cnt = min((ll)k, mx + 1);
        ans += cnt;
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
 * 前缀和 + 二分
 * 
 * 首先肯定是递增的
 * 
 * sum
 * 第 i 个数的和 sum * i / n + 
 */