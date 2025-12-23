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
    string s;
    cin >> s;
    auto calc = [&](char ch) {
        ll ans = 0;
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == ch) {
                ans += abs(i - (cnt++) * 2);
            }
        }
        return ans;
    };

    cout << min(calc('A'), calc('B')) << '\n';
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
/**
 * ABBBAA
 * ABBABA
 */