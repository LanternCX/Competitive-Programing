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
vector<int> dij(int st, vector<vector<edge>> g){
    int n = g.size();
    vector<int> vis(n);
    vector<int> dist(n, inf);

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

            if(!vis[x] && dist[x] > dist[now] + w){
                dist[x] = dist[now] + w;
                pq.push({dist[x], x});
            }
        }
    }

    return dist;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(6);
    arr[0] = 1;
    for(int i = 1; i <= 5; i++){
        cin >> arr[i];
    }
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int x, y, t;
        cin >> x >> y >> t;
        g[x - 1].push_back({y - 1, t});
        g[y - 1].push_back({x - 1, t});
    }
    int ans = inf;
    vector<vector<int>> dist;
    map<int, int> idx;
    for(int i = 0; i < 6; i++){
        idx[arr[i]] = i;
    }
    for(int i = 0; i < 6; i++){
        dist.push_back(dij(arr[i] - 1, g));
    }
    sort(arr.begin(), arr.end());
    do{
        int temp = 0;
        for(int i = 0; i < 5; i++){
            temp += dist[idx[arr[i]]][arr[i + 1] - 1];
        }
        ans = min(ans, temp);
    }while(next_permutation(arr.begin() + 1, arr.end()));
    cout << ans;
    return 0;
}