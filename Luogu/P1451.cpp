#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int vis[N + 10][N + 10];
int mp[N + 10][N + 10];

int dx[] = {0, 0, 1, -1};

int dy[] = {-1, 1, 0, -0};
struct node{
    int x, y;
};

int ans = 0;

void bfs(int m, int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            queue<node> q;
            if(vis[i][j] || mp[i][j] == 0){
                continue;
            }   
            q.push({i, j});
            // cout << i << ' ' << j << '\n';
            ans++;
            while(!q.empty()){
                node now = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int x = now.x + dx[i];
                    int y = now.y + dy[i];

                    if(mp[x][y] == 0){
                        continue;
                    }

                    if(!vis[x][y] && mp[x][y]){
                        q.push({x, y});
                        vis[x][y] = 1;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char ch;
            cin >> ch;
            mp[i][j] = ch - '0';
        }
    }
    bfs(m, n);
    cout << ans;
    return 0;
}