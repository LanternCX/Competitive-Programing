#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll binpow(ll a, ll b){
//     if(b == 1){
//         return a;
//     }
//     if(b == 0){
//         return 1;
//     }
//     if(b % 2 == 0){
//         ll res = binpow(a, b / 2);
//         return res * res;
//     }else{
//         ll res = binpow(a, b - 1);
//         return res * a;
//     }
// }
void sol(){
    ll n, m;
    cin >> n >> m;
    if(m == 1 || n == 1){ 
        cout << 1 << '\n';
        return;
    }
    ll ans = 1;
    ll x = m;
    while(x < n){
        ans++;
        x *= m;
    }
    if(n - x / m <= x - n && ans != 1){
        ans--;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * m ^ x = n 
 * x = log(n, m) = lnm / lnn
 */