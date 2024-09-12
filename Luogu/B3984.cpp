#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x, y;
    ll ans = 0;
    cin >> x >> y;
    ll n = y - x;
    cout << (n % 2 == 1 ? n / 2 + 1 : n / 2);
    return 0;
}