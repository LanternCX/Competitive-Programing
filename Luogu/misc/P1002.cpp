#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;
    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2));
    vector<int> dx = {-1, -1, 1, 1, -2, -2, 2, 2, 0};
    vector<int> dy = {-2, 2, -2, 2, -1, 1, -1, 1, 0};
    vector<pii> arr;
    for(int i = 0; i < 9; i++){
        if(x + dx[i] > n || x + dx[i] < 0 || y + dy[i] > m || y + dy[i] < 0){
            continue;
        }
        arr.push_back({x + dx[i], y + dy[i]});
    }
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            int tag = 0;
            for(auto [a, b] : arr){
                if(i == a && j == b){
                    dp[i][j] = 0;
                    tag = 1;
                    break;
                }
            }
            if(tag){
                continue;
            }
            dp[i + 1][j] += dp[i][j];
            dp[i][j + 1] += dp[i][j];
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n][m];
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
 * 8 6 0 4
 */