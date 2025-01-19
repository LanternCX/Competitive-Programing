#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
int inv = 0;
void sol(){
    ll l, r;
    cin >> l >> r;
    ll x = ((l % 9 + r % 9) % 9) * ((r - l + 1)) % 9 * inv % 9;
    cout << x % 9 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    int k;
    exgcd(2, 9, inv, k);
    inv = (inv % 9 + 9) % 9;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * (a + b) % p = (a % p + b % p) % p
 * (12345) % 9
 * = (1 * 10^4 + 2 * 10^3 + 3 * 10^2 + 4 * 10^1 + 5 * 10^0) % 9;
 * = (1 * 10^4 % 9 + 2 * 10^3 % 9 + 3 * 10^2 % 9 + 4 * 10^1 % 9 + 5 * 10^0 % 9) % 9;
 * = ((1 % 9 * 10^4 % 9) + ... + 5 % 9);
 * = (1 % 9 + 2 % 9 + 3 % 9 + 4 % 9 + 5 % 9);
 * = (1 + 2 + 3 + 4 + 5) % 9
 * 
 * ((l + r) * (r - l + 1) / 2) % 9
 * = ((l + r) * (r - l + 1) * inv(2)) % 9
 */