#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int m = 1e9 + 7;
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2) % m;
        return (res * res) % m;
    }else{
        ll res = binpow(a, b - 1) % m;
        return (a % m) * res;
    }
    return 1;
}
void sol(){
    ll a, x;
    cin >> a >> x >> m;
    ll ans = 0, temp = 1;
    while(x > 0){
        if(x % 2 == 1){
            ans = (ans % m + temp * binpow(a, x - 1) % m) % m;
        }
        x >>= 1;
        temp = (temp % m) * (1 + binpow(a, x) % m) % m;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}