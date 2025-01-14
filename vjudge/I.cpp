#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
using ll = long long;
int n, m, k;
char mp[N + 10][N + 10];
char vis[N + 10][N + 10];
struct node{
    int x, y;
    ll da = 0, db = 0;
};
struct person{
    int a, b;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
node bfs(){
    queue<node> q;
    q.push({1, 1});
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(!vis[now.x][now.y]){
            vis[now.x][now.y] = 1;
        }else {
            continue;
        }
        if(now.x == n && now.y == m){
            return now;
            break;
        }
        // cout << now.x << ' ' << now.y << '\n';
        for(int i = 0; i < 4; i++){
            node next = {
                now.x + dx[i], 
                now.y + dy[i], 
                now.da + max(dx[i], 0) + max(dy[i], 0), 
                now.db - min(dx[i], 0) - min(dy[i], 0)
            };
            if(mp[next.x][next.y] != 'X' && next.x > 0 && next.y > 0 && next.x <= n && next.y <= m){
                q.push(next);
            }
        }
    }
    return {0, 0};
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    node ans = bfs();
    vector<person> arr(k);
    ll minx = 1e18;
    for(int i = 0; i < k; i++){
        cin >> arr[i].a >> arr[i].b;
        ll temp = ans.da * arr[i].a + ans.db * arr[i].b;
        minx = minx < temp ? minx : temp; 
    }
    ll cnt = 0;
    for(int i = 0; i < k; i++){
        ll temp = ans.da * arr[i].a + ans.db * arr[i].b;
        if(temp == minx){
            cnt++;
        }
    }
    cout << minx << ' ' << cnt;
    return 0;
}