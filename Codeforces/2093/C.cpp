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

bool is_prime(ll x){
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (ll i = 3; i * i <= x; i += 2){
        if (x % i == 0) return false;
    }
    return true;
}

void sol(){
    ll x;
    int k;
    cin >> x >> k;
    
    if(k == 1){
        if (is_prime(x)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }else if (k == 2 && x == 1){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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