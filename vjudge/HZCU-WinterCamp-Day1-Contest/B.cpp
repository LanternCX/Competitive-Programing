#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p;
ll binpow(ll a, ll b){
    if(b == 0){
        return 1 % p;
    }
    if(b == 1){
        return a % p;
    }

    if(b % 2 == 0){
        ll res = binpow(a, b / 2) % p;
        return res * res; 
    }else{
        ll res = binpow(a, b - 1) % p;
        return res * (a % p);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld", a, b, p, binpow(a, b) % p);
    return 0;
}