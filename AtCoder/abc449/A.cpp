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
    float d;
    cin >> d;
    cout << (d / 2) * (d / 2) * M_PI << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}