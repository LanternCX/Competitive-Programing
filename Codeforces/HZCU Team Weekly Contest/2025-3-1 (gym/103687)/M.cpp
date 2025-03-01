#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int x, y;
};
int main(){
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mp(n + 2, vector<char>(m + 2));
	
	vector<vector<char>> tag(6, vector<char>(6));
	tag[0] = {'#', '#', '#', '#', '#', '#'};
	tag[1] = {'#', '#', '.', '.', '#', '#'};
	tag[2] = {'#', '.', '.', '.', '.', '#'};
	tag[3] = {'#', '.', '.', '.', '.', '#'};
	tag[4] = {'#', '#', '.', '.', '#', '#'};
	tag[5] = {'#', '#', '#', '#', '#', '#'};
	ll black = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
			black += mp[i][j] == '#';
		}
	}
	if(n < 9 || m < 9){
		cout << "0 0" << '\n';
		return 0;
	}
	vector<node> arr;
	for(int i = 1; i <= n - 6; i++){
		for(int j = 1; j <= m - 6; j++){
			int is = 1;
			for(int x = 0; x < 6; x++){
				for(int y = 0; y < 6; y++){
					if(mp[i + x][j + y] != tag[x][y]){
						is = 0;
					}
				}
			}
			if(is){
				arr.push_back({i, j});
			}
		} 
	}
	
	int cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		for(int j = i + 1; j < arr.size(); j++){
			if(abs(arr[i].x - arr[j].x) && arr[i].y == arr[j].y || abs(arr[i].y - arr[j].y) && arr[i].x == arr[j].x){
				cnt++;
			}
		}
	}
	cout << (arr.size() * 100 - black) / (54) << ' ';
	cout << arr.size() - 2 * ((arr.size() * 100 - black) / (54)) << '\n';
	return 0;
}