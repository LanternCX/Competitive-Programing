Luogu B3625

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

P1036

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7;
int k, n;
ll ans;
int arr[100];
struct node{
    int idx, val;
};

bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = false;
            }
        }
    }
}

void dfs(int sum, int cnt, int idx){
    if(cnt == k){
        if(p[sum]){
            // cout << sum << '\n';
            ans++;
        }
        return;
    }
    for(int i = idx; i < n; i++){
        dfs(sum + arr[i], cnt + 1, i + 1);
    }
    return;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ai();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0, 0 , 0);
    cout << ans;
    return 0;
}
```

P1498

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N  = 1024;
char a[1024][1024];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int len = 4, k = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = ' ';
        }
    }
    a[0][0] = a[1][1] = '/';
    a[0][1] = a[0][2] = '_';
    a[0][3] = a[1][2] = '\\';
    while (k < n) {
        for(int i = 0; i < len / 2; i++){
            for(int j = 0; j < len; j++){
                a[i + len / 2][j + len / 2] = a[i][j + len] = a[i][j];
            }
        }
        len *= 2;
        k++;
    }
    for(int i = (len / 2) - 1; i >= 0; i--){
        for(int j = 0; j < len; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
```

