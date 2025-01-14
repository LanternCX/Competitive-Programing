#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k;

    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = a[0] + b[0], r = a[n - 1] + b[m - 1];
    ll ans = 0;
    while(l < r){
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            cnt += upper_bound(b.begin(), b.end(), mid - a[i]) - b.begin();
        }
        // cout << l << ' ' << r << '\n';
        if(cnt > k){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
/**
 * c = a + b
 * b = c - a
 */