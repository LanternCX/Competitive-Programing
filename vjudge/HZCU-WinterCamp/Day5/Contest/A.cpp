#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x;
    cin >> x;
    ll n = floor(sqrt(2 * x) - 1.0 / 2);
    ll s = (1 + n) * n / 2;
    cout << x - s;
    return 0;
}
/**
 * s = (1 + n) * n / 2 = x
 * = n / 2 + n ^ 2 / 2
 * x = ? 
 * n ^ 2 + n - 2x = 0
 * n ^ 2 + n + 1/4 - 2x = 0
 * (n + 1/2)^2 = 2x
 * 
 * sqrt(2x) = n + 1/2
 * 
 * 1 + 2 + 3 + ... + n
 * a1 = 1
 * 
 * 
 */