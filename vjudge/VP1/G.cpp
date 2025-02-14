#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll binpow(ll a, ll b, ll p){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2, p) % p;
        return (res * res) % p;
    }else{
        ll res = binpow(a, b - 1, p) % p;
        return ((a % p) * res) % p;
    }
}
void sol(){
    ll x, y, n;
    cin>> x >> y >> n;
    for(int i = n - 1; i <= n + 1; i++){
        cout<< x * binpow(10, i, y) * 10 / y % 10;
    }
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