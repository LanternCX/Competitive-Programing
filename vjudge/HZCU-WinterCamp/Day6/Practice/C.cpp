#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, m;
    cin >> t >> m;
    vector<int> w(m + 1);
    vector<int> v(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(1e7 + 5);
    for(int i = 1; i <= m; i++){
        for(int j = w[i]; j <= t; j++){
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
        }
    }
    cout << dp[t];
    return 0;
}
/**
 * dp[w] = max(dp[w - w[i]] + v[i], dp[w])
 */