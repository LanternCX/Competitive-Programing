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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int now = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            now = i + k;
        } else { // s[i-1] == '0'
            if (i > now) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
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