#include <bits/stdc++.h>

using namespace std;

struct edge{
    int v, w;
};

struct node{
    int dis, id;
    auto operator > (node a)const {
        return dis > a.dis;
    }
};

const int inf = 1e9;

void sol(){
    int n, m, st;
    cin >>  n >> m >> st;
    st--;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
    }
    // cout << 1 << '\n';
    auto dij = [&](){
        vector<int> dist(n, inf);
        vector<int> vis(n);
        priority_queue<node, vector<node>, greater<node>> pq;

        dist[st] = 0;
        pq.push({0, st});
        
        while(!pq.empty()){
            int now = pq.top().id;
            pq.pop();
            // cout << now << '\n';
            if(vis[now]){
                continue;
            }

            vis[now] = 1;

            for(auto [v, w] : g[now]){
                if(dist[now] + w < dist[v]){
                    dist[v] = dist[now] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };
    auto dist = dij();
    for(auto x : dist){
        cout << x << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}