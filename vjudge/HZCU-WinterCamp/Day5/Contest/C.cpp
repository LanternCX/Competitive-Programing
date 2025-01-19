#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll binpow(ll x, ll n){
    if(n == 1){
        return x;
    }
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        ll res = binpow(x, n / 2);
        return res * res;
    }
    if(n % 2 == 1){
        ll res = binpow(x, n  - 1);
        return res * x;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }
    vector<pair<ll, ll>> row(n);
    vector<pair<ll, ll>> col(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 0){
                row[i].first++;
            }else {
                row[i].second++;
            }
        }
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(mp[i][j] == 0){
                col[j].first++;
            }else {
                col[j].second++;
            }
        }
    }
    ll ans = n * m;
    for(int i = 0; i < n; i++){
        if(row[i].first - 1 > 0){
            ans += binpow(2,row[i].first);
        }
        if(row[i].second - 1 > 0){
            ans += binpow(2,row[i].second);
        }
    }
    for(int i = 0; i < m; i++){
        if(col[i].first - 1 > 0){
            ans += binpow(2,col[i].first - 1);
        }
        if(col[i].second - 1 > 0){
            ans += binpow(2,col[i].second - 1);
        }
    }
    cout << ans;
    return 0;
}
/**
 * C(n, 1) + C(n, 2) + ... + c(n, n) = 2 ^ n
 */