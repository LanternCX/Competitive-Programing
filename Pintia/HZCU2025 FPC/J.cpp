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
    int n, q;
    cin >> n >> q;
    multiset<int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int w;
            cin >> w;
            st.insert(w);
        }
        if (op == 2) {
            int w;
            cin >> w;
            st.erase(st.find(w));
        }
        if (op == 3) {
            ans += *st.begin();
            cout << *st.begin() << '\n';
            st.erase(st.begin());
        }
    }
    cout << ans << '\n';
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