#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll sum1 = 0;
    ll sum2 = 0;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        sum1 += a;
    }
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        sum2 += a;
    }
    ll sum = sum1 + sum2;
    int ans = ceil(sum / (2.0));
    cout << ans;
    return 0;
}