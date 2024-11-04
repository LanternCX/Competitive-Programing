#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[2005][2005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    for(ll t = 0; t < k; t++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1]++;
        a[x2 + 1][y1]--;
        a[x1][y2 + 1]--;
        a[x2 + 1][y2 + 1]++;
    }
    for(ll i = 1; i <= n + 1; i++){
        for(ll j = 1; j <= m + 1; j++){
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    
    for(ll i = 1; i <= n + 1; i++){
        for(ll j = 1; j <= m + 1; j++){
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    for(ll i = 0; i < q; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}

/**
 * 1 1 1 1
 * 1 1 1 1
 * 1 1 1 1
 * 1 1 1 1
 * 
 * 4 4 1 2
 * 1 1 4 4
 * 1 1 4 4
 * 1 1 3 3 
 * 
 */
/**
4 4 1 2
1 1 4 4
1 1 4 4
1 1 3 3 
 */