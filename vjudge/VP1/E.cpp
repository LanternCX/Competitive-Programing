#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    int id;
    ll val;
};
struct edge{
    int v, w;
};
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    auto bfs = [&](int u, int v){
        ll ans = LONG_LONG_MAX;
        vector<int> vis(n);
        queue<node> q;
        q.push({u, (int) g[u].size()});
        while(!q.empty()){
            node now = q.front();
            q.pop();
            // cout << now.id << '\n';
            if(now.id == v){
                ans = min(now.val, ans);
                continue;
            }
            if(vis[now.id] == 1){
                continue;
            }
            vis[now.id] = 1;
            for(auto x : g[now.id]){
                if(vis[x]){
                    continue;
                }
                q.push({x, now.val + (int) g[x].size()});
            }
        }
        return ans;
    };
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << bfs(u, v) << '\n';
    }
    return 0;
}
/**
 * 堆优化dij?
 */