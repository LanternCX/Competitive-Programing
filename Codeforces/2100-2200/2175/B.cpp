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
void sol() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> p(n + 1), a(n + 1);

    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }

    p[r] = p[l - 1];

    for(int i = 1; i <= n; i++) {
        a[i] = p[i] ^ p[i - 1];
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}