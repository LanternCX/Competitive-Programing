#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node{
	int x, y, d;
};
const int inf = INT_MAX;
void sol(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mp(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		while(r--){
			int x;
			cin >> x;
			x--;
			mp[i][x] = 1;
		}
	}
	int ans = INT_MAX;
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, -1, 1};
//	vector<vector<int>> d(n, vector<int>(m, inf));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	
	auto bfs = [&](){
		queue<node> q;
		for(int st = 0; st < n; st++){
			if(mp[st][0] != 1){
				q.push({st, 0, 0});
				vis[st][0] = 0;
			}
		}
		
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int x = now.x + dx[i];
				int y = now.y + dy[i];
				if(x < 0 || x >= n || y < 0 || y >= m){
					continue;
				}
				if(mp[x][y] == 1){
					continue;
				}
				if(now.d + 1 > ans){
					continue;
				}
				if(vis[x][y]){
					continue;
				}
				if(y == m - 1){
					ans = min(ans, now.d + 1);
					return;
				}
				q.push({x, y, now.d + 1});
				vis[x][y] = 1;
			}
		}
	};
	bfs();
	cout << ans + 1 << '\n';
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
	} 
	return 0;
} 