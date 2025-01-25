#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n);
    dp[0] = a[0];
    int ans = INT_MIN;
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}