#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[1000][1000];
void sol(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	int x = 1, y = 1;
	for(int i = 1; i <= n; i++){
		x = i;
		y = 1;
		int mn = 1e7;
		while(x <= n && y <= n){
//			cout << x << ' ' << y << '\n';
			mn = min(a[y][x] , mn);
			x++;
			y++;
		}
		ans += -min(0, mn);
	}
	x = 1, y = 1;
	for(int i = 2; i <= n; i++){
		y = i;
		x = 1;
		int mn = 1e7;
		while(x <= n && y <= n){
//			cout << x << ' ' << y << '\n';
			mn = min(a[y][x] , mn);
			x++;
			y++;
		}
		ans += -min(0, mn);
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		sol();
	}
	return 0;
}