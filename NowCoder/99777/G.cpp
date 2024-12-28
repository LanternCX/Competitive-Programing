#include <bits/stdc++.h>

using namespace std;
struct node{
	int x, y;
};
struct point{
	int x, y;
};
int vis[20][100010];
int bfs(vector<vector<vector<node>>> mp, int x, int y){
	for(int i = 0; i <= 10; i++){
		for(int j = 0; j <= 1e5; j++){
			vis[i][j] = 0;
		}
	}
	vector<point> ans;
	queue<point> q;
	q.push({x, y});
	while(!q.empty()){
		point now = q.front();
		q.pop();
		ans.push_back(now);
//		cout << now.x << ' ' << now.y << '\n';
		vis[now.x][now.y] = 1;
		
		for(node nd : mp[now.x][now.y]){
			if(!vis[nd.x][nd.y] && now.x != -1 && now.y != -1){
				q.push({nd.x, nd.y});
			}
		}
	}
//	for(int i : ans){
//		cout << i << ' ';
//	}
//	cout << '\n';
	return ans.size() - 1;
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<node>>> mp;
	vector<vector<node>> l(m + 10);
	for(int i = 0; i <= n; i++){
		mp.push_back(l);
	}
	while(k--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		mp[a][b].push_back({c, d});
		mp[c][d].push_back({a, b});
	}
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			int idx = -1;
			
			for(int i = 0; i < mp[a][b].size(); i++){
				node nd = mp[a][b][i];
				if(nd.x == c && nd.y == d){
					idx = i;
				}
			}
			if(idx != -1){
				mp[a][b][idx].x = -1;
				mp[a][b][idx].y = -1;
			}
		}
		if(op == 2){
			int x, y;
			cin >> x >> y;
			cout << bfs(mp, x, y) << '\n';
		}
	}
	return 0;
}
/**
 * To Be Done
 */