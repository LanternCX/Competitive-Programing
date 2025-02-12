#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void sol(){
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][1] = c2;
    ll ans = (n - 1) * c1;
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i][1] = i * c1;
        for(int j = 1; j <= i; j++) {
            if(a[i] >= a[i - j] && b[i] >= b[i - j]) {
                // 删掉前 i 个 或者 从删掉从 i 往前的 j - 1 个转移
                dp[i][0] = min(dp[i][0], dp[i - j][0] + (j - 1) * c1);
                dp[i][1] = min(dp[i][1], dp[i - j][1] + (j - 1) * c1);
            }
            if(a[i] >= b[i - j] && b[i] >= a[i - j]) {
                dp[i][0] = min(dp[i][0], dp[i - j][1] + (j - 1) * c1);
                dp[i][1] = min(dp[i][1], dp[i - j][0] + (j - 1) * c1);
            }
        }
        dp[i][1] += c2;
        ans = min(ans, min(dp[i][0], dp[i][1]) + (n - i - 1) * c1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * dp[x][0 / 1]表示以位置 x 作为结尾，位置 x 处是否交换时所最小和法序列的代价
 */