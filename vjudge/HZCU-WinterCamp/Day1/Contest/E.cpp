#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
char mp[N + 10][N + 10];
int vis[N + 10][N + 10];
struct node{
    int x, y;
    int is;
    int l;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, k;
int bfs(){
    queue<node> q;
    q.push({1, 1, 0, 0});

    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(vis[now.x][now.y] >= now.is){
            continue;
        }
        vis[now.x][now.y] = now.is;
        // cout << '{' << now.x << ' ' << now.y << '}' << now.is << " l:" << now.l<< '\n';
        if(now.x == now.y && now.x == n){
            return now.l;
        }
        if(now.is > 0){
            now.is--;
        }
        for(int i = 0; i < 4; i++){
            node next = {now.x + dx[i], now.y + dy[i], now.is, now.l + 1};
            if(next.x > n || next.y > n || next.x < 1 || next.y < 1){
                continue;
            }
            if(mp[next.x][next.y] == '#'){
                continue;
            }
            if(mp[next.x][next.y] == 'X' && next.is == 0){
                continue;
            }

            if(mp[next.x][next.y] == '%'){
                next.is = k + 1;
            }
            q.push(next);
        }
    }
    return {};
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            vis[i][j] = -1;
        }
    }
    cout << bfs();
    return 0;
}
/**
 * 
...XX
##%#.
...#.
.###.
.....
 */