#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e7 + 1e3;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p;
    cin >> n >> p;
    array<int, N> inv;
    inv[1] = 1;
    cout << 1 << '\n';
    for (int i = 2; i <= n; ++i) {
        inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        cout << inv[i] << '\n';
    }
    return 0;
}

// solve1: exgcd
// /**
//  * solve ax + by = gcd(a, b)
//  */
// void exgcd(ll a, ll b, ll &x, ll &y) {
//     if (b == 0) {
//         x = 1, y = 0;
//         return;
//     }
//     exgcd(b, a % b, y, x);
//     y -= a / b * x;
// }

// int main(){
//     ll n, p;
//     cin >> n >> p;
//     for(ll i = 1; i <= n; i++){
//         ll x, k;
//         exgcd(i, p, x, k);
//         x = (x % p + p) % p;
//         cout << x << '\n';
//     }

// }
// /**
//  * ax = 1 (mod p)
//  * 
//  * ax + kp = gcd(a, b) = 1
//  */

// solve2: binpow
// ll binpow(ll a, ll b, ll mod){
//     if(b == 0){
//         return 1;
//     }
//     if(b % 2 == 0){
//         ll res = binpow(a, b / 2, mod) % mod;
//         return res * res;
//     }else{
//         ll res = binpow(a, b - 1, mod) % mod;
//         return (a % mod) * res;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     ll n, p;
//     cin >> n >> p;
//     for(ll i = 1; i <= n; i++){
//         cout << binpow(i, p - 2, p) % p << '\n';
//     }
//     return 0;
// }