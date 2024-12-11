#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    ll mxa = 0, mxb = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mxa = max(mxa, a[i]);
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
        mxb = max(mxb, b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = 0, r = mxa + mxb;
    while(l < r){
        ll mid = (l + r) / 2;
        
        ll sum = 0;
        for(ll x : a){
            ll cnt = upper_bound(b.begin(), b.end(), mid - x) - b.begin();
            sum += cnt;
        }

        // cout << l << ' ' << r << '\n';
        if(sum > k){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}