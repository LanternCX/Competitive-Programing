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
    
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    if(!(cin >> t)) return 0;
    const ll NMAX = 1000000000LL;
    vector<ll> p;
    p.push_back(1);
    for(int i=1;i<40;i++){
        p.push_back(p.back() * 3LL);
    }
    int max = 0;
    for(int i=0;i<(int)p.size();i++){
        if(p[i] <= NMAX) max = i;
        else break;
    }
    vector<ll> res(max+1, 0);
    res[0] = 3;
    for(int i = 1; i <= max; i++){
        res[i] = p[i+1] + (ll)i * p[i-1];
    }

    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        for(int i = max; i >= 0; --i){
            if(n <= 0) break;
            ll cnt = n / p[i];
            if(cnt > 0){
                ans += cnt * res[i];
                n -= cnt * p[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}