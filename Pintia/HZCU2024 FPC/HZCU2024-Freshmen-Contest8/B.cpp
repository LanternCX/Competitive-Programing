#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
struct node{
	int x, y;
	int l;
};
int n, m;
char mp[N + 10][N + 10];
int vis[N + 10][N + 10];
int dx[] = {2, -2, 1, -1, 2, -2, 1, -1};
int dy[]  = {1, -1, 2, -2, -1, 1, -2, 2};
void bfs(int x1, int y1, int x2, int y2){
	bool tag = 0;
	queue<node> q;
	if(x1 == x2 && y1 == y2){
		cout << 0;
		return;
	}
	q.push({x1, y1, 0});
	vis[x1][y1] = 1;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int x = now.x + dx[i];
			int y = now.y + dy[i];
			
			if(x > n || y > m || x <= 0 || y <= 0){
				continue;
			}
			
			if(vis[x][y]){
				continue;
			}
//			cout << x << ' ' << y << '\n';
			if(x == x2 && y == y2){
				cout << now.l + 1;
				return;
			}
			
			q.push({x, y, now.l + 1});
			vis[x][y] = 1;
		}
	}
	cout << 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x1, y1;
	int x2, y2;
	cin >> n >> m;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	bfs(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
	return 0;
}