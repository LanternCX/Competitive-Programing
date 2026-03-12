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

struct node {
    int idx, val;    
    bool operator>(node a) const {
        return val > a.val;
    }
};

void sol() {
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        auto &[x, idx] = a[i];
        cin >> x;
        idx = i;
    }

    sort(a.begin(), a.end());

    while (q--) {
        debug(q);
        int k;
        cin >> k;
        vector<int> b(k);
        for (auto &x : b) {
            cin >> x;
            x--;
        }
        sort(b.begin(), b.end());
        for (auto &[val, idx] : a) {
            debug(val, idx);
            if (find(b.begin(), b.end(), idx) != b.end()) {
                continue;
            } else {
                cout << val << '\n';
                break;
            }
        }
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