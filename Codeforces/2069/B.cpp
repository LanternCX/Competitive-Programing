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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 2, vector<int>(m + 2));
    map<int, int> a;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
            a[mp[i][j]] = 1;
        }
    }
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int tag = 0;
            for(int k = 0; k < 4; k++){
                if(mp[i][j] == mp[i + dx[k]][j + dy[k]]){
                   a[mp[i][j]] = 2;
                }
            }
        }
    }
    int ans = 0;
    int mx = 0;
    debug(a);
    for(auto p : a){
        ans += p.second;
        mx = max(p.second, mx);
    }
    cout << ans - mx << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
0 1 1 1
0 1 1 1
1 1 0 0

1   2  
  4   1
2   3  

有 n 种颜色一定要涂 n - 1 次
多出来的就和联通有关

每多一个大小大于 1 的连通块就要多涂 1 次
最后一个连通块可以不涂
 */