#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct edge{
    int x, w;
};
struct node{
    int dist, id;
    bool operator>(node a) const {
        return dist > a.dist;
    }
};
int dij(int st, int ed, vector<vector<edge>> g){
    int n = g.size();
    vector<int> vis(n);
    vector<int> dist(n, inf);
    vector<int> fa(n);

    priority_queue<node, vector<node>, greater<node>> pq;
    
    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        int now = pq.top().id;
        pq.pop();

        if(vis[now]){
            continue;
        }

        vis[now] = 1;

        for(auto nd : g[now]){
            int x = nd.x;
            int w = nd.w;

            if(!vis[x] && dist[x] > w){
                dist[x] = w;
                pq.push({dist[x], x});
                fa[x] = now;
            }
        }
    }

    vector<int> res = {ed};
    int now = ed;
    int ans = 0;
    while(now != st){
        res.push_back(fa[now]);
        now = fa[now];
    }
    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size() - 1; i++){
        auto arr = g[res[i]];
        int temp = inf;
        for(auto nd : arr){
            if(nd.x == res[i + 1]){
                temp = min(temp, nd.w);
            }
        }
        ans = max(temp, ans);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }

    cout << dij(s - 1, t - 1, g);
    return 0;
}