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
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int ans = 0;
    int tail = 0;
    for (int i = 0; i < n; i++) {
        if (i > tail) {
            break;
        }
        tail = max(tail, i + a[i] - 1);
    }
    cout << min(tail + 1, n) << '\n';
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