#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    vector<ll> diag1;
    auto calc1 = [&](ll x, ll y) -> ll {
        ll sum = 0;
        while(x <= n && y <= m){
            if(x == n + 1 || y == m + 1){
                break;
            }
            // cout << x << ' ' << y << '\n';
            sum += mp[x][y];
            x++;
            y++;
        }
        return sum;
    };
    for(ll i = m; i >= 1; i--){
        diag1.push_back(calc1(1, i));
    }
    for(ll i = 2; i <= n; i++){
        diag1.push_back(calc1(i, 1));
    }
    // reverse(diag1.begin(), diag1.end());
    vector<ll> diag2;
    auto calc2 = [&](ll x, ll y) -> ll {
        ll sum = 0;
        while(x <= n && y <= m && x > 0 && y > 0){
            if(x == n + 1 || y == m + 1 || y == 0 || x == 0){
                break;
            }
            // cout << x << ' ' << y << '\n';
            sum += mp[x][y];
            x--;
            y++;
        }
        return sum;
    };
    for(ll i = 1; i <= n; i++){
        diag2.push_back(calc2(i, 1));
    }
    for(ll i = 2; i <= m; i++){
        diag2.push_back(calc2(n, i));
    }
    // for(ll x : diag1){
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for(ll x : diag2){
    //     cout << x << ' ';
    // }
    // cout << '\n';
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            ll temp = 0;
            // cout << i + j + m - 2 << ' ' << i + j - 2 << '\n';
            temp += diag1[i - j + m - 1];
            temp += diag2[i + j - 2];
            temp -= mp[i][j];
            ans = max(temp, ans);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 2, 3 -> 3, 3
 * 
 * 
 */