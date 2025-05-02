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
    int n;
    cin >> n;
    ll ans=0;
    for(ll i = n - 1; i > 0; i -= 2){
        ans += i;
    }
    cout << ans + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        debug(t);
        sol();
    }
    return 0;
}
/**
 * 1 2 3 4 -> 0
 * 
 * 1 2 3 4
 * 0 0 0 0
 * 
 * 2 1 3 4
 * 1 1 0 0 
 * 
 * 2 3 1 4
 * 1 1 2 0
 * 
 * 0 + 2 + 4 + ... + 
 * 1 2 3
 */