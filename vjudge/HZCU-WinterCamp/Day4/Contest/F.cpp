#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
void fol(int k, vector<vector<int>> &g){
    int n = g.size();
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(g[i][k] != inf && g[k][j] != inf){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> g(n, vector<int>(n, inf));
    for(int i = 0; i < n; i++){
        g[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }
    int q;
    cin >> q;
    int now = 0;
    while(q--){
        int x, y, t;
        cin >> x >> y >> t;
        while(arr[now] <= t && now < n){
            fol(now, g);
            now++;
        }
        if(g[x][y] == inf){
            cout << -1 << '\n';
            continue;
        }
        if(arr[x] > t || arr[y] > t){
            cout << -1 << '\n';
            continue;
        }
        cout << g[x][y] << '\n';
    }
    return 0;
}