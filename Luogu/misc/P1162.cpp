#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int mp[N + 10][N + 10];
int vis[N + 10][N + 10];
int n;

struct node{
    int x, y;
    bool isopen;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<node> dfs(){
    vector<node> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            queue<node> q;
            if(vis[i][j] || mp[i][j] != 0){
                continue;
            }
            q.push({i, j});
            ans.push_back({i, j});
            while(!q.empty()){
                node now = q.front();
                q.pop();

                if(vis[now.x][now.y]){
                    continue;
                }

                vis[now.x][now.y] = 1;

                for(int i = 0; i < 4; i++){
                    int x = now.x + dx[i];
                    int y = now.y + dy[i];

                    if(mp[x][y] == -1){
                        ans[ans.size() - 1].isopen = 1;
                        continue;
                    }

                    if(mp[x][y] == 1){
                        continue;
                    }

                    if(mp[x][y] == 0){
                        q.push({x, y});
                    }
                }
            }
        }
    }
    return ans;
}

void fill(node nd){
    queue<node> q;
    q.push({nd.x, nd.y});
    while(!q.empty()){
        node now = q.front();
        q.pop();

        if(vis[now.x][now.y]){
            continue;
        }

        vis[now.x][now.y] = 1;
        mp[now.x][now.y] = 2;

        for(int i = 0; i < 4; i++){
            int x = now.x + dx[i];
            int y = now.y + dy[i];

            if(mp[x][y] == 1){
                continue;
            }

            if(mp[x][y] == 0){
                q.push({x, y});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            mp[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mp[i][j];
        }
    }
    vector<node> ans = dfs();
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            vis[i][j] = 0;
        }
    }
    for(node nd : ans){
        if(!nd.isopen){
            fill(nd);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}