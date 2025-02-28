#include<bits/stdc++.h>

using namespace std;

void sol(){
	int n;
	cin >> n;
	vector<string> arr(n);
	map<string, int> mp;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	int ans = 0;
	ans += mp["Au"];
	ans += min(mp["Cu"], mp["Ag"]); 
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}