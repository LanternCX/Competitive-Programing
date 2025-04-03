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
    int v, n;
    cin >> v >> n;
    vector<int> w(n);
    for(auto &x : w){
        cin >> x;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(v + 1));
    debug(dp[n]);
    for(int i = 1; i <= n; i++){
        dp[i][w[i - 1]] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = v; j >= 0; j--){
            dp[i][j] = dp[i - 1][j] | dp[i][j];
            if(j - w[i - 1] >= 0){
                dp[i][j] = dp[i][j] | dp[i - 1][j - w[i - 1]];
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= v; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = v; i >= 0; i--){
        if(dp[n][i]){
            cout << v - i;
            return;
        }
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
/**
 * 状态定义
 * dp[i][j] 表示从前 i 个物品中拿 j 个的箱子容量的最小值
 * 
 * dp[i][j] 表示考虑前 i 个物品，箱子容量为 j 的拿法是否存在
 * 
 * dp[i][j] = dp[i - 1][j] | dp[i - 1][j - w[i]]
 * 
 * dp[j] = dp[j] | dp[j - w[i]]
 */