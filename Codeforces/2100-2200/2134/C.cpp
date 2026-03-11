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
    int n; cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    vector<ll> pre(n + 1,0), cap(n + 1,0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + ( (i % 2 == 0) ? a[i] : -a[i] );
        cap[i] = cap[i-1] + ( (i % 2 == 1) ? a[i] : 0 );
    }
    vector<ll> arr(n + 1,0);
    arr[0] = 0;
    ll is = 0;
    ll ans = 0;
    const ll INF = (ll) - 9e18;
    ll mx = INF;
    for(int i = 1; i <= n; i++){
        if(i-2 >= 0) {
            mx = max(mx, arr[i-2]);
        }
        ll temp = pre[i] + is;
        if(temp < mx){
            ll need = mx - temp;
            ll ok = cap[i] - is;
            if(ok < need){
                need = ok;
            }
            is += need;
            ans += need;
            temp += need;
        }
        arr[i] = temp;
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