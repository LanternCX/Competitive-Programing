#include <bits/stdc++.h>
using namespace std;
// int ansmp[15][15];
struct node{
    int x, y;
};
int ans = 0;
int n;
void dfs(node now, int l, vector<vector<int>> mp, vector<vector<int>> vis){
    if(l == n + 1){
        ans++;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mp[i][j] == 1){
                    if(ans <= 3){
                        cout << j << ' ';
                    }
                    // ansmp[i][j] = 1;
                }
            }
        }
        if(ans <= 3){
            cout << '\n';
        }
        return;
    }

    vis[now.x][now.y] = 1;
    vector<node> next;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[i][j]){
                next.push_back({i, j});
            }
        }
    }
    if(next.empty()){
        return;
    }
    for(node nd : next){
        vector<vector<int>> tempvis = vis;
        vector<vector<int>> tempmp = mp;
        int x = nd.x;
        int y = nd.y;
        if(vis[nd.x][nd.y]){
            continue;
        }

        while (x > 0 && x <= n && y > 0 && y <= n) {
            tempvis[x][y] = 1;
            x++;
            y++;
        }
        x = nd.x;
        y = nd.y;
        while (x > 0 && x <= n && y > 0 && y <= n ) {
            tempvis[x][y] = 1;
            x--;
            y--;
        }
        x = nd.x;
        y = nd.y;
        while (x > 0 && x <= n && y > 0 && y <= n) {
            tempvis[x][y] = 1;
            x++;
            y--;
        }
        x = nd.x;
        y = nd.y;
        while (x > 0 && x <= n && y > 0 && y <= n) {
            tempvis[x][y] = 1;
            x--;
            y++;
        }
        for(int i = 1; i <= n; i++){
            tempvis[i][nd.y] = 1;
            tempvis[nd.x][i] = 1;
        }
        tempmp[nd.x][nd.y] = 1;
        dfs(nd, l + 1, tempmp, tempvis);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<vector<int>> mp;
    for(int i = 0; i <= n; i++){
        vector<int> temp(n + 1);
        for(int i = 0; i <= n; i++){
            temp[i] = 0;
        }
        mp.push_back(temp);
    }
    vector<vector<int>> vis;
    for(int i = 0; i <= n; i++){
        vector<int> temp(n + 1);
        for(int i = 0; i <= n; i++){
            temp[i] = 0;
        }
        vis.push_back(temp);
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            vis[i][j] = 1;
            dfs({i, j}, 1, mp, vis);
        }
    }
    cout << ans;
    return 0;
}
/**
 * To Be Done
 */