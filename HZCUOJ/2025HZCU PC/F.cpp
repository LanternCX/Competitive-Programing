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
    int q, k;
    cin >> q >> k;
    set<pii> s;
    int head = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx, len;
            cin >> idx >> len;
            int l = idx, r = idx + len - 1;
            if (r < head || l > head + k - 1) {
                continue;
            }
            l = max(head, l);
            r = min(r, head + k - 1);
            s.insert({l, r});
            debug(s);
        }
        if (op == 2) {
            int tag = 0;
            int pre_head = head;
            vector<pii> erase;
            for (auto [l, r] : s) {
                if (l <= head) {
                    head = max(head, r + 1);
                    tag = 1;
                    erase.push_back({l, r});
                } else {
                    break;
                }
            }

            for (auto p : erase) {
                s.erase(p);
            }

            if (tag) {
                cout << pre_head << ' ' << head << '\n';
            } else {
                cout << -1 << ' ' << -1 << '\n';
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