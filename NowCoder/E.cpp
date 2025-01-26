#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> lx;
    vector<ll> rx;
    for(int i = 0; i < n; i++){
        ll p, v;
        cin >> p >> v;
        if(v < 0){
            lx.push_back(p);
        }else {
            rx.push_back(p);
        }
    }
    sort(lx.begin(), lx.end());
    sort(rx.begin(), rx.end());
    ll cnt = 0;
    for(ll x : rx){
        cnt += lx.end() - lower_bound(lx.begin(), lx.end(), x);
    }
    if(cnt < k){
        cout << "No\n";
        return 0;
    }else {
        cout << "Yes\n";
    }
    ll l = 0, r = 1e9 + 10;
    ll ans = 0;
    while(l < r){
        ll mid = (l + r + 1) / 2;
        ll cnt = 0;
        for(ll x : rx){
            cnt += lx.end() - lower_bound(lx.begin(), lx.end(), x);
            cnt -= lx.end() - lower_bound(lx.begin(), lx.end(), max(x + mid, 0LL));
        }
        // cout << l << ' ' << r << ' ' << mid <<'\n';
        if(cnt < k){
            l = mid;
        }else if(cnt >= k){
            r = mid - 1;
        }
        ans = mid;
    }
    printf("%.6lf", 1.0 * ans / 2);
    return 0;
}