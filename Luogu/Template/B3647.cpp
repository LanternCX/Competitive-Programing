#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
void sol(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, inf));
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u][v] = min(w, g[u][v]);
        g[v][u] = min(w, g[u][v]);
    }
    
    for(int i = 0; i < n; i++){
        g[i][i] = 0;
    }

    vector<vector<int>> dp = g;

    auto floyd = [&](){
        // dp[i][j] 表示 i 到 j 的最短路径的长度 
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dp[i][k] != inf && dp[k][j] != inf){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
    };

    floyd();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
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