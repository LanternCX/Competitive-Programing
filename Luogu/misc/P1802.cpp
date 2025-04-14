#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    int n, x;
    cin >> n >> x;
    vector<int> lose(n), win(n), use(n);
    for(int i = 0; i < n; i++){
        cin >> lose[i] >> win[i] >> use[i];
    }
    vector<ll> dp(x + 1);
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(j >= use[i]){
                dp[j] = max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
            }else {
                dp[j] = dp[j] + lose[i];
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) * 5ll;
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
 * 状态定义：
 * dp[i][j] 表示考虑前 i 个敌人, 使用 j 的药物能获得的最大价值
 * 
 * 转移：
 * 考虑前 i 个敌人可以从考虑前 i - 1 个敌人转移
 * 如果可以打败
 * 选择打败获得 win[i] 选择不打败获得 lose[i]
 * dp[i][j] = max(dp[i - 1][j - use[i]] + win[i], dp[i - 1][j] + lose[i])
 * 
 * 如果不能打败
 * 获得 lose[i]
 * dp[i][j] = dp[i - 1][j] + lose[i]
 */