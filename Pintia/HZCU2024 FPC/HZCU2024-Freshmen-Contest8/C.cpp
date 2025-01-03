#include<bits/stdc++.h>
using namespace std;
int n, m, a, b;
const int N = 500;
struct node{
	int x, y;
	int l;
};
char mp[N + 10][N + 10];
int ans[N + 10][N + 10];
int vis[N + 10][N + 10];
int dx[] = {-1, 1, 0, 0};
int dy[]  = {0, 0, -1, 1};
void bfs(vector<node> arr1){
	queue<node> q;
	for(node nd : arr1){
		q.push(nd);
	}
	while(!q.empty()){
		node now = q.front();
		q.pop();
		if(vis[now.x][now.y] == 1){
			continue;
		}
		vis[now.x][now.y] = 1;
		ans[now.x][now.y] = now.l;
		// cout << now.x << ' ' << now.y << ' ' << now.l << '\n';
		for(int i = 0; i < 4; i++){
			int x = now.x + dx[i];
			int y = now.y + dy[i];
			if(vis[x][y]){
				continue;
			}

			if(x <= 0 || x > n || y <= 0 || y > m){
				continue;
			}

			q.push({x, y, now.l + 1});
		}
	}
} 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			ans[i][j] = -1;
		}
	}
	vector<node> arr1(a);
	vector<node> arr2(b);
	for(int i = 0; i < a; i++){
		node nd; 
		cin >> nd.x >> nd.y;
		nd.l = 0;
		arr1[i] = nd;
	}
	for(int i = 0; i < b; i++){
		node nd; 
		cin >> nd.x >> nd.y;
		arr2[i] = nd;
	}
	bfs(arr1);
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		cout << ans[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	for(node nd : arr2){
		cout << ans[nd.x][nd.y] << '\n';
	}
	return 0;
}