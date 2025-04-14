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
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for(auto &x : w){
        cin >> x;
    }

    vector<int> dp(m + 1);
    for(int i = 0; i < n; i++){
        for(int j = m; j >= 0; j--){
            if(j - w[i] < 0){
                continue;
            }
            dp[j] += (w[i] == j) + dp[j - w[i]];
        }
    }
    debug(dp);
    cout << dp[m] << '\n';
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
/**
 * 完全背包
 * 
 * dp[i][j] 表示考虑前 i 个物品背包容量为 j 的方案数
 * 
 * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - w[i]]
 * 
 * dp[j] += dp[j - w[i]]
 */