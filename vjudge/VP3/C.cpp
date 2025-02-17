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
const int N = 1e5;
void sol(){
    int n;
    cin >> n;
    vector<int> w(n);

    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> w[i];
        sum += w[i];
    }
    vector<vector<int>> dp(n, vector<int>(sum  + *max_element(w.begin(), w.end())));
    
    for(int i = 0; i < n; i++){
        dp[i][w[i]] = 1;
    }

    // 1e7
    for(int i = 1; i < n; i++){
        for(int j = sum; j > 0; j--){
            if(j == w[i]){
                dp[i][j] = 1;
            }
            if(dp[i - 1][j] == 1){
                dp[i][j] = 1;
            }
            if(dp[i - 1][j + w[i]] == 1){
                dp[i][j] = 1;
            }
            if(dp[i - 1][abs(j - w[i])] == 1){
                dp[i][j] = 1;
            }
        }
    }

    ll cnt = 0;
    for(int i = 1; i <= sum; i++){
        if(dp[n - 1][i] == 1){
            debug(i);
            cnt++;
        }
    }
    cout << cnt;
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
 * 背包？
 * dp[j] = dp[j - w[i]] + v[i], dp[j]
 * 
 * 定义：
 * 设 dp[i][j] 表示 前 i 个砝码能否称出 j
 * 转移：
 * 从能称出的 j 转移
 * 1) 前 i - 1 个能称出的 前 i 个一定能称出 dp[i][j] = dp[i - 1][j]
 * 2) 前 i - 1 个不能称出的 判断加上第 i 个能否称出 dp[i - 1][j + w[i]] 和 dp[i - 1][j - w[i]] 可以
 */