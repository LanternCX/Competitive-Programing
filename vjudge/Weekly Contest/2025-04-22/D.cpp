#include <bits/stdc++.h>
using namespace std;
void sol(){
	int n;
	cin >> n;
	vector<vector<int>> mp(n, vector<int>(n, -1));
	int t = n * n;
	vector<int> arr = {1, 2, 3};
	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};
	auto work = [&](int a){
        for(int c = 1; c <= 3; c++){
            if(c == a){
                continue;
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(mp[i][j] != -1){
                        continue;
                    }
                    int res = 1;
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || y < 0 || x >= n || y >= n){
                            continue;
                        }
                        if(mp[x][y] == c){
                            res = 0;
                            break;
                        }
                    }
                    if(res){
                        cout << c << ' ' << i + 1 << ' ' << j + 1 << '\n';
                        mp[i][j] = c;
                        return;
                    }
                } 
            }
        }
	};
	while(t--){
		int a;
		cin >> a;
		work(a);
		// cout.flush();
	}
}
signed main(){
	// ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
} 
/**
a ^ b = a + b - 2 * ( a & b )
2 1
3 
*/