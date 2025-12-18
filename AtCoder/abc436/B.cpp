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
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    mp[0][(n - 1) / 2] = 1;
    int x = 0, y = (n - 1) / 2;
    for (int i = 2; i <= n * n; i++) {
        int xi = (x - 1 + n) % n;
        int yi = (y + 1 + n) % n;
        // debug(xi, yi);
        if (mp[xi][yi] == 0) {
            mp[xi][yi] = i;
        } else {
            xi = (x + 1) % n;
            yi = y;
            mp[xi][yi] = i;
        }
        x = xi;
        y = yi;
    }
    for (auto arr : mp) {
        for (auto x : arr) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}