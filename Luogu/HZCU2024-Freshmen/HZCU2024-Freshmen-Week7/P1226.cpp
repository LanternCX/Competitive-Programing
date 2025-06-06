#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll binpow(ll a, ll b, ll mod){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2, mod) % mod;
        return res * res;
    }else{
        ll res = binpow(a, b - 1, mod) % mod;
        return (a % mod) * res;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld", a, b, p, binpow(a, b, p) % p);
    return 0;
}