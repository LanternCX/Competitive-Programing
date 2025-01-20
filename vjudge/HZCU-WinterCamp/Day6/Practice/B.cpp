#include <bits/stdc++.h>
using namespace std;
struct node{
    int t, v;
};
int dp[105][1005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, m;
    cin >> t >> m;
    vector<node> arr(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> arr[i].t >> arr[i].v;
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = t; j >= 0; j--){
            if(arr[i].t <= j){
                dp[i][j] = max(dp[i - 1][j - arr[i].t] + arr[i].v, dp[i - 1][j]);
            }else {
                dp[i][j] = dp[i - 1][j];
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;
    return 0;
}
/**
 * dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - t[i]] + v[i])
 */