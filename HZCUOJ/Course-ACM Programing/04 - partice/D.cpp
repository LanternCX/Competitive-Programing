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

const int inf = 1e7;

void sol(){
    int n, m, st = 0;
    vector<vector<edge>> g;
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
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            return;
        }
        g.clear();
        g.resize(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        
        auto dist = dij();
        cout << dist[n - 1] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}