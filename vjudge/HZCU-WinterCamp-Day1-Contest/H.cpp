#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int mp[N + 10][N + 10];
int pre[N + 10][N + 10];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x, y, v;
        cin >> x >> y >> v;
        mp[x + 1][y + 1] += v;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            pre[i][j] = mp[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int ans = 0;
    for(int i = m; i <= N; i++){
        for(int j = m; j <= N; j++){
            int sum = pre[i][j] - pre[i - m][j] - pre[i][j - m] + pre[i - m][j - m];
            ans = max(sum, ans);
        }
    }
    cout << ans;
    return 0;
}
/**
 * 1 1 1 
 * 1 1 1
 * 1 1 1
 */