#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, p;
    cin >> n >> p;
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for(int i = 2; i <= n; i++){
        inv[i] = (ll) (p - p / i) * inv[p % i] % p;
    }
    for(int i = 1; i <= n; i++){
        cout << inv[i] << '\n';
    }
    return 0;
}