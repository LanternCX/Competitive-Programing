#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
void floyd(vector<vector<int>> &g){
    int n = g.size();
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (g[i][k] != inf && g[k][j] != inf) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; ++i) {
        g[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1][v - 1] = min(w, g[u - 1][v - 1]);
        g[v - 1][u - 1] = min(w, g[u - 1][v - 1]);
    }
    floyd(g);
    for(auto l : g){
        for(int x : l){
            if(x == inf){
                cout << "inf ";
            }else{
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}