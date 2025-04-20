#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m)), ans(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int res = 0;
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    res += max(abs(i - x), abs(j - y)) * s[i][j];
                }
            }
            ans[i][j] = res;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " \n"[j == m - 1]; 
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}
