#include <bits/stdc++.h>
using namespace std;
const int N = 400;
int n, m, x, y;
struct node{
    int x, y, l;
};

int mp[N + 10][N + 10];
int vis[N + 10][N + 10];
int ans[N + 10][N + 10];

int dx[] = {2, 1, -2, -1, -2, -1, 2, 1};
int dy[] = {1, 2, 1, 2, -1, -2, -1, -2};

void bfs(){
    queue<node> q;
    q.push({x, y});
    while(!q.empty()){
        node now = q.front();
        q.pop();

        if(vis[now.x][now.y]){
            continue;
        }

        ans[now.x][now.y] = now.l;
        vis[now.x][now.y] = 1;
        // cout << now.x << ' ' << now.y << '\n';
        
        for(int i = 0; i < 8; i++){
            int x = now.x + dx[i];
            int y = now.y + dy[i];

            if(vis[x][y]){
                continue;
            }

            if(x > n || y > m || x < 1 || y < 1){
                continue;
            }

            q.push({x, y, now.l + 1});
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> x >> y;
    // cout << bfs(3, 2);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ans[i][j] = -1;
        }
    }
    bfs();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}