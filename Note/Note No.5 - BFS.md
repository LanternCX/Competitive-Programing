# ACM Note No.5：BFS

广度优先搜索常常用于寻找全局最短路，遍历联通块等等，是一种暴力算法

下面是一个广度优先搜索的模板题：

其中可以通过更改`dx[]`和`dy[]`数组来更改步进的行为（如马走日字格等）

记得要打上`vis[]`数组标记访问过的地址不然会死循环

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char mp[110][110];
bool vis[110][110];

struct node{
    int x, y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(int n, int m){
    bool tag = 0;
    queue<node> q;
    if(mp[1][1] == '.'){
        q.push({1, 1});
        vis[1][1] = 1;
    }

    while(!q.empty()){
        node now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = now.x + dx[i];
            int y = now.y + dy[i];
            if(vis[x][y]){
                continue;
            }

            if(mp[x][y] != '.' && mp[x][y] != '#'){
                continue;
            }

            if(x == n && y == m){
                tag = 1;
                break;
            }
            
            if(mp[x][y] != '#'){
                // cout << x << ' ' << y << '\n';
                q.push({x, y});
            }
            vis[x][y] = 1;
        }

        if(tag){
            break;
        }
    }
    return tag;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    cout << (bfs(n, m) ? "Yes" : "No");
    return 0;
}
```
