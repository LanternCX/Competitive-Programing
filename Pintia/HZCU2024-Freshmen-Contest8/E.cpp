#include<bits/stdc++.h>
using namespace std;
const int N = 100;
struct node{
	int x, y;
};
char mp[N + 10][N + 10];
int vis[N + 10][N + 10];
int dx[] = {-1, 1, 0, 0};
int dy[]  = {0, 0, -1, 1};
bool bfs(int n, int m){
	bool tag = 0;
	queue<node> q;
	if(mp[1][1] == '.'){
		q.push({1, 1});
		vis[1][1] = 1;
	}
	
	while(!q.empty()){
		node now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int x = now.x + dx[i];
			int y = now.y + dy[i];
			if(vis[x][y]){
				continue;
			}
			
			if(mp[x][y] != '.' && mp[x][y] != '#'){
				continue;
			}
			
			if(x == n && y == m){
				tag = 1;
				break;
			}
			
			if(mp[x][y] != '#'){
				q.push({x, y});
			}
			vis[x][y] = 1;
		}
		
		if(tag){
			break; 
		}
	}
	return tag;
} 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
		}
	}
	cout << (bfs(n, m) ? "Yes" : "No");
	return 0;
}