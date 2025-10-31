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
    int m;
    cin >> m;
    set<int> st;
    while (m--) {
        int op, len;
        cin >> op >> len;
        if (op == 1) {
            if (st.count(len)) {
                cout << "Already Exist\n";
            } else {
                st.insert(len);
            }
        }
        if (op == 2) {
            if (st.empty()) {
                cout << "Empty\n";
                continue;
            }
            auto it = st.lower_bound(len);
            int r = *it;
            if (it != st.begin()) {
                it--;
            }
            int l = *it;
            if (abs(l - len) <= abs(r - len)) {
                cout << l << '\n';
                st.erase(l);
            } else {
                cout << r << '\n';
                st.erase(r);
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