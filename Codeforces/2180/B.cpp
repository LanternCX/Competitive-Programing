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
    vector<string> a(n);
    for (auto &s : a) {
        cin >> s;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        string s = a[i];
        if (ans + s < s + ans) {
            ans = ans + s;
        } else {
            ans = s + ans;
        }
    }
    cout << ans << '\n';
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