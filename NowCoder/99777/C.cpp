#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	int idx = 0;
	vector<int> ans(2);
	for(auto p : mp){
		if(p.second == 1){
			ans[idx++] = p.first;
		}
	}
	if(ans[0] > ans[1]){
		cout << ans[1] << ' ' << ans[0];
	}else{
		cout << ans[0] << ' ' << ans[1]; 
	}
	return 0;
}