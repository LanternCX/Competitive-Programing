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
    vector<int> p(n), a(n);
    vector<int> idx(n + 1); 

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        idx[p[i]] = i;
    }

    for (auto &x : a) {
        cin >> x;
    }

    int pre = -1;
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i-1]) {
            continue;
        }

        int cur = idx[a[i]];

        if (cur < pre) {
            cout << "NO\n";
            return;
        }

        pre = cur;
    }
    
    cout << "YES\n";
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