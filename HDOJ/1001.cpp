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
const int p = 1e9 + 7;
void sol(){
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<ll>> dp(m + 1, vector<ll>(v + 1));
    vector<int> w(n);
    for(auto &x : w){
        cin >> x;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 0; k <= v; k++){
                if (k >= w[i]) {
                    dp[j][k] = (dp[j][k] + dp[j - 1][k - w[i]]) % p;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int k = 0; k <= v; k++) {
        ans = (ans + dp[m][k]) % p;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * dp?
 * 
 * 考虑前 i 个
 * 可以转移到第 i + 1 个
 * 
 * 首先完全背包的角度考虑
 * 可以求出最大值
 * 完全背包考虑的是对于给定的物品重量
 * 计算背包容量下能获得的最大价值
 * 
 * 这里的背包容量可以转换为价总花费 v
 * 每个物品有 1 的重量
 * 也就是说最多可以拿 m 个物品
 * 
 * 但是问题在于如何计数
 * 可以把 dp 数组修改为统计数量
 * 
 * 首先
 * dp[i][j] 表示只考虑前 i 个物品的情况下，背包容量为 j 时的方案数
 * dp[i][j] = dp[i - 1][j] + dp[i][j - w[i]]
 * 然后枚举起点？
 * 好像不太对
 * 
 * 
 * dp[i][j][k] 表示考虑前 i 个物品，选择恰好 j 个物品，总花费恰好为 k 的方案数
 * 首先可以从 j - 1 转移
 * dp[j][k] = (dp[j][k] + dp[j - 1][k - w[i]]);
 * 好像是对的emm
 * 好像可以优化一维防mle
 * 
 */