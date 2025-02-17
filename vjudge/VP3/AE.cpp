#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
int lcm(int a, int b){return (a * b) / gcd(a, b);}
struct node{
    int dis, id;
    bool operator>(node a) const {
        return dis > a.dis;
    }
};
struct edge{
    int v, w;
};
vector<int> dij(int st, vector<vector<edge>> g){
    int n = g.size();
    vector<int> dist(n);
    vector<bool> vis(n);
    vector<int> fa(n);
    const int inf = INT_MAX;
    priority_queue<node, vector<node>, greater<node>> pq;
    fill(dist.begin(), dist.end(), inf);
    
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
            int v = nd.v;
            int w = nd.w;
            if(!vis[v] && dist[now] + w < dist[v]){
                dist[v] = dist[now] + nd.w;
                pq.push({dist[v], v});
                fa[v] = now;
            }
        }
    }
    return dist;
}
void sol(){
    const int N = 2021;
    vector<vector<edge>> g(N + 1);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(abs(i - j) <= 21){
                g[i].push_back({j, lcm(i, j)});
                g[j].push_back({i, lcm(i, j)});
            }
        }
    }
    auto dist = dij(1, g);
    cout << dist[2021];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}