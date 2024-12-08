#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
char mp[N + 10][N + 10];
int n, m, t;
struct node{
	int x, y;
}now;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
		}
	}
	cin >> now.y >> now.x;
	now.x += 1;
	now.y += 1;
	while(t--){
		char op;
		cin >> op;
		if(op == 'D'){
			int y = now.y + 1;
			int x = now.x;
			if(y <= 0){
				y = n;
			}else if(y > n){
				y = 1;
			}
			
			if(mp[y][x] == '#'){
				y = now.y;
			}
			
			now.y = y;
		}
		
		if(op == 'U'){
			int y = now.y - 1;
			int x = now.x;
			if(y <= 0){
				y = n;
			}else if(y > n){
				y = 1;
			}
			
			if(mp[y][x] == '#'){
				y = now.y;
			}
			
			now.y = y;
		}
		
		if(op == 'L'){
			int x = now.x - 1;
			int y = now.y;
			if(x <= 0){
				x = m;
			}else if(x > m){
				x = 1;
			}
			
			if(mp[y][x] == '#'){
				x = now.x;
			}
			
			now.x = x;
		}
		
		if(op == 'R'){
			int x = now.x + 1;
			int y = now.y;
			if(x <= 0){
				x = m;
			}else if(x > m){
				x = 1;
			}
			
			if(mp[y][x] == '#'){
				x = now.x;
			}
			
			now.x = x;
		}
//		cout << now.x << ' ' << now.y << '\n';
	}
	cout << now.y - 1 << ' ' << now.x - 1;
	return 0;
}