#include<bits/stdc++.h>

using namespace std;

void sol(){
	int n;
	cin >> n;
	vector<string> a(n);
	map<string, int> cnt;
	map<string, int> vis;
	for(auto &x : a){
		cin >> x;
		cnt[x]++;
	}
	for(int i = 0; i < a.size(); i++){
		if(!vis[a[i]]){
			cout << a[i] << ' ' << cnt[a[i]] << '\n';
			vis[a[i]] = 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
	}
	return 0; 
} 