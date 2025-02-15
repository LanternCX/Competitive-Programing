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
struct node{
    ll id, val;
};
void sol(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x;
    }
    auto check = [&](ll mid) -> bool {
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            if(a[i] < mid){
                if(mid - a[i] > b[i]){
                    return 0;
                }
                sum += mid - a[i];
                
            }
        }
        return sum <= m;
    };
    ll l = 0, r = 1e18;
    ll ans = 0;
    while(l < r){
        ll mid = (l + r) / 2;
        debug(l, r, mid);
        if(check(mid)){
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    cout << l;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 
 */