#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll ans1 = 0;
    ll ans2 = 0;
    ll a = 1, b = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            a = i;
            b = j;
            if(a == b){
                ans1 += (n - a + 1) * (m - b + 1);
            }else{
                ans2 += (n - a + 1) * (m - b + 1);
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}