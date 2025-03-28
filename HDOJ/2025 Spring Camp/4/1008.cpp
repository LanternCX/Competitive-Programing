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

const ll INF = 1e18;
void sol(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> pre(k, vector<ll>(n + 1, 0));
    for (int j = 0; j < k; j++){
        for (int i = 1; i <= n; i++){
            pre[j][i] = pre[j][i - 1] + a[i - 1][j];
        }
    }

    vector<ll> dp = pre[0];
    for (int i = 1; i < k; i++){
        vector<ll> ndp(n+1, 0);
        ll res = LLONG_MIN;
        for (int j = 0; j <= n; j++){
            res = max(res, dp[j] - pre[i][j]);
            ndp[j] = pre[i][j] + res;
        }
        dp = ndp;
    }

    cout << dp[n] << "\n";
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 对于每一个段落 i 
 * 下标要大于等于上一个
 * 那要如何选择？
 * 直接贪心？
 * 
 * 1 2 3 
 * 1 2 3  
 * 1 2 3
 * 选 3 3 3 
 * 
 * 2 1 1 1
 * 1 2 3 10
 * 1 3 10000 1
 * 
 * 好像都不对
 * 
 * dp? 背包?
 * 
 * 首先 下标要递增
 * 然后 和要最大
 * 
 * dp[i][j] 表示前 i 个元素分成 j 段的最大开心值
 * 
 * 分成 j 段可以从 分成 j - 1 段和 分成 j 段转移
 * 
 * 从 分成 j - 1 段转移：
 *  dp[i][j] = a[i][j] + dp[i - 1][j - 1]
 * 从 分成 j 段转移：
 *  dp[i][j] = a[i][j] + dp[i - 1][j];
 * 
 * dp[i][j] = max(a[i][j] + dp[i - 1][j - 1], a[i][j] + dp[i - 1][j])
 */