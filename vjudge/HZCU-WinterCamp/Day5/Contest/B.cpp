#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b , a % b);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll lc = lcm(x, y);
    cout << b / lc - (a - 1) / lc;
    return 0;
}
/**
 * 18 - 6 = 12
 * 6 12 18
 * b / lc - a / lc
 */