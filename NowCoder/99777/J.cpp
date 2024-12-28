#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
int mp[N + 10][N + 10];
void sol(){
	int n, m;
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mp[i][j];
		} 
	}
	for(int i = 0; i < n; i++){
		int tag = 0;
		for(int j = 0; j < m; j++){
			if(mp[i][j] == 1){
				a = i;
				b = j;
				tag = 1;
				break;
			}
		}
		if(tag){
			break;
		}
	}
	int a1, b1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mp[i][j] == 1){
				a1 = i;
				b1 = j;
			}
		}
	}
//	cout << a << ' ' << b << endl << a1 << ' ' << b1 << endl;
	int ans = 0;
	for(int i = a; i <= a1; i++){
		for(int j = b; j <= b1; j++){
			if(mp[i][j] == 0){
				ans = 1;
				break;
			}
		}
	}
	cout << (ans ? "Yes\n" : "No\n");
}

int main(){
	int t;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}