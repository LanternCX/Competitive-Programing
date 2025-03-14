#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
int n, m;
struct point{
    int x, y;
};
struct node{
    int dis, x, y, dir;
    bool operator>(node a) const {
        return dis > a.dis;
    }
};

int id(int i, int j){
	return i * m + j;
}

vector<vector<int>> dij(int stx, int sty, vector<vector<int>> t, vector<vector<int>> d){
    vector<int> dist(n * m);
    vector<int> dir(n * m); 
    vector<bool> vis(n * m);
    vector<int> dx(4), dy(4);
    dx = {1, -1, 0, 0};
    dy = {0, 0, 1, -1};
    priority_queue<node, vector<node>, greater<node>> pq;
    fill(dist.begin(), dist.end(), inf);
    
    dist[id(stx, sty)] = 0;
    pq.push({0, stx, sty, 2});
    
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
       	
        if(vis[id(now.x, now.y)]){
            continue;
        }
        
//        debug(now.x, now.y); 
        vis[id(now.x, now.y)] = 1;
        dir[id(now.x, now.y)] = now.dir;
        
        for(int i = 0; i < 4; i++){
        	int x = now.x + dx[i];
        	int y = now.y + dy[i];
        	
        	if(x >= n || y >= m || x < 0 || y < 0){
        		continue;
			}
        	int w;
        	if(now.dir != i){
        		w = t[now.x][now.y] + d[now.x][now.y];
			}else{
				w = t[now.x][now.y];
			}
//			debug(now.x, now.y, x, y, w);
			if(!vis[id(x, y)] && dist[id(now.x, now.y)] + w < dist[id(x, y)]){
//				debug("in", x, y);
                dist[id(x, y)] = dist[id(now.x, now.y)] + w;
                pq.push({dist[id(x, y)], x, y, i});
            }
		}
    }
    return {dist, dir};
}
void sol() {
	cin >> n >> m;
	vector<vector<int>> t(n, vector<int>(m)), d(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> t[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> d[i][j];
		}
	}
	auto res = dij(0, 0, t, d);
	auto dist = res[0];
	auto dir = res[1];
	ll w = 0;
	
	if(dir[id(n - 1, m - 1)] != 3){
		w = t[n - 1][m - 1] + d[n - 1][m - 1];
	}else{
		w = t[n - 1][m - 1];
	}
	cout << dist[id(n - 1, m - 1)] + w << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
/**
1 2 3 4
0 : +x
1 : -x;
2 : +y;
3 : -y;

To be done
*/