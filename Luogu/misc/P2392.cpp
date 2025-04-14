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
    ll ans = 0;
    vector<int> s(4);
    for(auto &x : s){
        cin >> x;
    }
    for(int i = 0; i < 4; i++){
        int n = s[i];
        ll sum = 0;
        vector<int> w(n);
        for(auto &x : w){
            cin >> x;
            sum += x;
        }
        vector<int> dp(sum / 2 + 1);
        for(int i = 0; i < n; i++){
            for(int j = sum / 2; j >= 0; j--){
                if(j - w[i] < 0){
                    continue;
                }
                dp[j]=max(dp[j], dp[j - w[i]] + w[i]);
            }
        }
        ans += sum - dp[sum / 2];
    }
    cout << ans << '\n';
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
 * 转化为若干个物品
 * 
 * dp[i][j] 表示考虑前面 i 个物品，j 时间下的代价
 * 
 * dp[i][j] = max(dp[i - 1][j], dp[j - w[i]] + w[i])
 * 
 */