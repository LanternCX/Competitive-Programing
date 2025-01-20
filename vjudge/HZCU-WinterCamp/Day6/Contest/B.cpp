#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
ll dp[50][50];
int dx[] = {1, 2, 1, 2};
int dy[] = {2, 1, -2, -1};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    dp[5][5] = 1;
    for(int i = 5; i <= m + 5; i++){
        for(int j = 5; j <= n + 5; j++){
            for(int k = 0; k < 4; k++){
                dp[i + dx[k]][j + dy[k]] += dp[i][j];
            }
        }
    }
    cout << dp[m + 5][n + 5];
    return 0;
}
/**
 * (2, 1)
 * dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1]
 */