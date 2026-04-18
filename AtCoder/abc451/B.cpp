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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    map<int, int> pre, post;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    for (auto x : a) {
        pre[x]++;
    }

    for (auto x : b) {
        post[x]++;
    }

    for (int i = 0; i < m; i++) {
        cout << post[i] - pre[i] << '\n';
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