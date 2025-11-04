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
    set<string> st;
    while (n--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string x;
            cin >> x;
            if (k > 1) {
                st.insert(x);
            }
        }
    }

    cin >> n;
    set<string> ans;
    while (n--) {
        string x;
        cin >> x;
        if (!st.count(x) && !ans.count(x)) {
            if (ans.size()) {
                cout << ' ';
            }
            cout << x;
            ans.insert(x);
        }
    }
    if (!ans.size()) {
        cout << "No one is handsome\n";
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