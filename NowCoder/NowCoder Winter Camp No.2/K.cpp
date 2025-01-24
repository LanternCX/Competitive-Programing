#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> fa;
    int n;
    DSU(int size) {
        n = size;
        fa = vector<int>(n);
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    bool query(int x, int y){
        return find(x) == find(y);
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1, -1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x;
            cin >> x;
            mp[i][j] = x - '0';
        }
    }
    DSU dsu(n * m + 1);
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    auto id = [&](int x, int y) -> int {
        return (x - 1) * m + y;
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 1 || x > n || y < 1 || y > m){
                    continue;
                }
                if(mp[x][y] == 1 && mp[i][j] == 1){
                    dsu.merge(id(i, j), id(x, y));
                }
            }
        }
    }
    vector<set<int>> res(n * m + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] != 1){
                continue;
            }
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 1 || x > n || y < 1 || y > m){
                    continue;
                }
                if(mp[x][y] == 0){
                    res[dsu.find(id(i, j))].insert(id(x, y));
                }
            }
        }
    }
    int ans = n * m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] != 1){
                continue;
            }
            ans = min(ans, (int) res[dsu.find(id(i, j))].size());
        }
    }
    cout << ans;
    return 0;
}