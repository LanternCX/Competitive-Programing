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
    int T = 1;
    while (true) {
        vector<int> cnt(7);
        int sum = 0;
        for (int i = 1; i <= 6; ++i) {
            cin >> cnt[i];
            sum += cnt[i] * i;
        }
        if (accumulate(cnt.begin(), cnt.end(), 0) == 0) break;

        cout << "Collection #" << T++ << ":\n";

        if (sum % 2 != 0) {
            cout << "Can't be divided.\n\n";
            continue;
        }

        int w = sum / 2;
        vector<int> dp(w + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= 6; i++) {
            int num = cnt[i];
            for (int k = 1; num > 0; k <<= 1) {
                int use = min(k, num);
                for (int j = w; j >= i * use; j--) {
                    if (dp[j - i * use]) dp[j] = 1;
                }
                num -= use;
            }
        }

        cout << (dp[w] ? "Can be divided.\n\n" : "Can't be divided.\n\n");
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
