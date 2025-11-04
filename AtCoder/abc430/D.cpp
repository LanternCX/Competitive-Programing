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
    set<int> st;
    vector<int> arr(n);
    map<int, int> res;
    for (auto &x : arr) {
        cin >> x;
    }

    st.insert(0);
    res[0] = INT_MAX;

    ll ans = 0;
    for (auto x : arr) {
        auto it = st.lower_bound(x);
        int l = -1, r = -1;
        if (it != st.begin()) {
            auto itl = prev(it);
            l = *itl;
        }
        if (it != st.end()) {
            r = *it;
        }

        // 在插入 x 之前，减去受影响的左右两人的旧贡献
        if (l != -1 && res[l] != INT_MAX) {
            ans -= res[l];
        }
        if (r != -1 && res[r] != INT_MAX) {
            ans -= res[r];
        }

        st.insert(x);

        // 更新三个人的最近距离
        if (l != -1) {
            res[l] = min(res[l], abs(x - l));
        }
        if (r != -1) {
            res[r] = min(res[r], abs(x - r));
        }
        res[x] = INT_MAX;
        if (l != -1) {
            res[x] = min(res[x], abs(x - l));
        }
        if (r != -1) {
            res[x] = min(res[x], abs(x - r));
        }

        // 加回新的贡献
        if (l != -1) {
            ans += res[l];
        }
        if (r != -1) {
            ans += res[r];
        }
        ans += res[x];

        cout << ans << '\n';
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
