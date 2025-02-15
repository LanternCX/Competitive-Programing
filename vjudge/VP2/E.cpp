#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
void sol(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a){
        cin >> x;
    }
    ll ans = 0;
    vector<ll> cnt(n);
    for(int i = 0; i < n; i++){
        ll temp = a[i];
        while(temp > 1){
            cnt[i]++;
            temp = sqrtl(ll(temp / 2LL) + 1LL);
        }
    }
    ll mx = *max_element(cnt.begin(), cnt.end());
    for(int i = mx; i > 0; i--){
        for(int j = 0; j < n; j++){
            if(cnt[j] == i && a[j] != a[j + 1]){
                ans++;
            }
            if(cnt[j] == i){
                cnt[j]--;
                a[j] =  sqrtl(ll(a[j] / 2LL) + 1LL);
                debug(a);
            }
        }
    }
    cout << ans;
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}