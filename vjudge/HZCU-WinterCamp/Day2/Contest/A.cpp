#include <bits/stdc++.h>
using namespace std;
struct node{
    int id;
    vector<int> nd;
};
int bfs(int begin, vector<vector<int>> mp){
    int res = begin;
    queue<node> q;
    vector<int> vis(mp.size());
    q.push({begin, mp[begin]});
    while(!q.empty()){
        node now = q.front();
        q.pop();
        if(vis[now.id]){
            continue;
        }
        vis[now.id] = 1;
        res = max(res, now.id);
        for(int x : mp[now.id]){
            q.push({x, mp[x]});
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        mp[u - 1].push_back(v - 1);
    }
    for(int i = 0; i < n; i++){
        cout << bfs(i, mp) + 1 << ' ';
    }
    return 0;
}