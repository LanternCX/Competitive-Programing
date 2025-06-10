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
void sol(){
    string s;
    while ( (cin >> s) && s != "0" ) {
        int n = s.size();
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i >= 2) {
                int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (two >= 10 && two <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }

        cout << dp[n] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}