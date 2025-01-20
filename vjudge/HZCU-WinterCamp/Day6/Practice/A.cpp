#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r;
    cin >> r;
    vector<vector<int>> mp(r, vector<int>(r));
    vector<vector<int>> dp(r, vector<int>(r));
    for(int i = 0; i < r; i++){
        for(int j = 0; j <= i; j++){
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    dp[0][0] = mp[0][0];
    for(int i = 1; i < r; i++){
        dp[i][0] = dp[i - 1][0] + mp[i][0];
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j] + mp[i][j], dp[i - 1][j - 1] + mp[i][j]);
            ans = max(dp[i][j], ans);
        }
    }
    // for(int i = 0; i < r; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans;
    return 0;
}
/**
 * 
 * max(f(r, i)) = max(f(r - 1, i) + n, f(r - 1, i - 1) + x)
 */