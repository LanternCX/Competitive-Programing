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
    int n, m, k;
    cin >> n >> m >> k;
    while (k--) {
        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;
        int idx = 1;
        stack<int> st;
        int tag = 0;
        for (auto x : arr) {
            if (x == idx) {
                idx++;
                while (!st.empty() && st.top() == idx) {
                    st.pop();
                    idx++;
                }
            } else {
                st.push(x);
                if ((int)st.size() > m) {
                    tag = 1;
                    break;
                }
            }
        }
        if (!tag && idx == n + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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