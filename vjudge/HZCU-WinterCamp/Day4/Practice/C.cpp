#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct edge{
    int v, w;
};
struct node{
    int dist, id;
    bool  operator>(node a) const {
        return dist > a.dist;
    }
};

vector<int> dij(int st, int ed, vector<vector<edge>> g){
    int n = g.size();
    vector<int> dist(n);
    vector<int> vis(n);
    vector<int> fa(n);
    priority_queue<node, vector<node>, greater<node>> pq;
    fill(dist.begin(), dist.end(), inf);
    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()){
        int now = pq.top().id;
        pq.pop();
        if(vis[now]){
            continue;
        }
        vis[now] = 1;
        for(edge nd : g[now]){
            int v = nd.v;
            int w = nd.w;
            if(!vis[v] && dist[v] > dist[now] + w){
                dist[v] = dist[now] + w;
                pq.push({dist[v], v});
                fa[v] = now;
            }
        }
    }
    vector<int> res = {ed};
    if(dist[ed] == inf){
        return res;
    }
    int now = ed;
    while(now != st){
        res.push_back(fa[now]);
        now = fa[now];
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;    
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        g[a - 1].push_back({b - 1, w});
        g[b - 1].push_back({a - 1, w});
    }
    vector<int> ans = dij(0, n - 1, g);
    if(ans.size() <= 1){
        cout << -1;
    }else{
        for(int x : ans){
            cout << x + 1 << ' ';
        }
    }
    return 0;
}