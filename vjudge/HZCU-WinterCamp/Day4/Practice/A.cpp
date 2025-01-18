#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
struct edge{
    int v, w;
};
struct node{
    int dis, id;
    bool operator>(node a) const {
        return dis > a.dis;
    }
};
vector<int> dij(int st, vector<vector<edge>> g){
    priority_queue<node, vector<node>, greater<node>> pq;
    int n = g.size();
    vector<int> dist(n);
    vector<bool> vis(n);
    fill(dist.begin(), dist.end(), inf);
    fill(vis.begin(), vis.end(), 0);

    dist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        // 找到未访问节点中距离最短的节点
        int now = pq.top().id;
        pq.pop();
        if(vis[now]){
            continue;
        }

        // 访问节点 next 并将该节点标记为已访问
        vis[now] = 1;

        // 计算通过[原点到达节点 next 的最短路]到达[所有未访问节点的距离]
        // 如果距离比先前计算的小就进行更新
        for(auto nd : g[now]){
            int v = nd.v;
            int w = nd.w;
            if(!vis[v] && dist[now] + w < dist[v]){
                dist[v] = dist[now] + nd.w;
                // 将待访问节点更新进入优先队列
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<edge>> g(n);

    // 输入并建图
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
    }

    vector<int> dist = dij(s - 1, g);
    for(int x : dist){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}