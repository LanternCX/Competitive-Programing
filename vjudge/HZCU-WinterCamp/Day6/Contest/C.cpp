#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(dp[i], ans);
        }
    }
    cout << ans;
    return 0;
}
/**
 * dp[i] = max(dp[x] + 1, dp[i])
 */