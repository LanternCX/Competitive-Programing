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
ll MOD = 998244353;
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2) % MOD;
        return (res * res) % MOD;
    }else{
        ll res = binpow(a, b - 1) % MOD;
        return ((a % MOD) * res) % MOD;
    }
}
const ll N = 1e5;
bool p[N + 10];
void ai(){
    for(ll i = 0; i <= N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(ll i = 2; i * i <= N; i++){
        if(p[i]){
            for(ll j = i * i; j <= N; j += i){
                p[j] = false;
            }
        }
    }
}
void sol(){
    ll x, y, n;
    cin >> x >> y >> n;
    y /= x;
    vector<ll> c;
    for(ll i = 2; i * i <= y; i++){
        if(!p[i]){
            continue;
        }
        ll cnt = 0;
        while(y % i == 0){
            cnt++;
            y /= i;
        }
        debug(cnt);
        if(cnt != 0){
            c.push_back(cnt);
        }
    }
    if(y > 1){
        c.push_back(1);
    }
    ll ans = 1;
    for(auto x : c){
        ll tmp = ((binpow(x + 1, n) - 2 * binpow(x, n)) % MOD + binpow(x - 1, n)) % MOD;
        tmp = (tmp + MOD) % MOD;
        ans = ans * tmp % MOD;
    }
    cout << ans << '\n';
}
void init(){
    ai();
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    ll t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}