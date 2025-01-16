#include <bits/stdc++.h>
using namespace std;
struct node{
    int id;
    vector<int> nd;
};

int bfs(int begin, vector<vector<int>> g){
    queue<node> q;
    vector<int> vis(g.size());
    q.push({begin, g[begin]});
    int res = begin;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(vis[now.id]){
            continue;
        }
        vis[now.id] = 1;
        res = max(res, now.id);
        for(auto x : g[now.id]){
            q.push({x, g[x]});
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    for(int i = 0; i < n; i++){
        cout << bfs(i, g) + 1 << ' ';
    }
    return 0;
}