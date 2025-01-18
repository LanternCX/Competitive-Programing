#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int x, y, op;
struct node{
    int t, id;
};
void flo(int x, vector<vector<int>> &g){
    int n = g.size();
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(g[i][x] != inf && g[x][j] != inf){
                g[i][j] = min(g[i][j], g[i][x] + g[x][j]);
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
        int x, y, op;
        cin >> x >> y >> op;
        
        while(arr[now] <= op && now < n){
            flo(now, g);
            now++;
        }
        if(arr[x] > op || arr[y] > op){
            cout << -1 << '\n';
            continue;
        }
        if(g[x][y] == inf){
            cout << -1 << '\n';
            continue;
        }
        cout << g[x][y] << '\n';
    }
    return 0;
}