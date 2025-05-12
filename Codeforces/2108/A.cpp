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
void sol(){
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n % p == 0) {
        int k = n / p;
        if (m == k * q) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    else {
        cout << "YES\n";
    }
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