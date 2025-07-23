#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
void sol(){
    ll a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    ll g = gcd(a, b);

    if (a == 0 && b == 0) {
        cout << 0 << '\n';
        return;
    }

    if ((a == 0 && b != 0) || (a != 0 && b == 0)) {
        cout << 1 << '\n';
        return;
    }

    if (a / g <= k && b / g <= k) {
        cout << 1 << '\n';
        return;
    }

    cout << 2 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 首先 0 1 2
 * 
 * (0, 1) (1, 0)
 * 
 * 不考虑 k
 * 
 * 互质的话 2
 * 否则 1
 * 
 * 
 */