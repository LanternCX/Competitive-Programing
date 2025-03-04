#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int x, y;
};
void sol(){
	int h, w;
	cin >> h >> w;
	vector<vector<int>> mp(h, vector<int>(w));
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> mp[i][j];
		}
	}
	
	map<int, int> m;
	ll ans = 0;
	vector<vector<int>> vis(h, vector<int>(w));
	
	auto dfs = [&](auto&& dfs, node now) -> void {
		int x = now.x;
		int y = now.y;
//		cout << mp[x][y] << '\n';
		if(x == h - 1 && y == w - 1){
			ans++;
			return;
		}
		
		{
			node next = {now.x, now.y + 1};
			if(next.x < h && next.y < w && !vis[next.x][next.y]){
				if(m[mp[next.x][next.y]] == 0){
//					vis[next.x][next.y] = 1;
					m[mp[next.x][next.y]]++;
					
					dfs(dfs, next);
					
					m[mp[next.x][next.y]]--;
//					vis[next.x][next.y] == 0;
				}
			}
		}
		
		{
			node next = {now.x + 1, now.y};
			if(next.x < h && next.y < w && !vis[next.x][next.y]){
				if(m[mp[next.x][next.y]] == 0){
//					vis[next.x][next.y] = 1;
					m[mp[next.x][next.y]]++;
					
					dfs(dfs, next);
					
					m[mp[next.x][next.y]]--;
//					vis[next.x][next.y] == 0;
				}
			}
		}
	};
	m[mp[0][0]]++;
	dfs(dfs, {0, 0});
	cout << ans;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}