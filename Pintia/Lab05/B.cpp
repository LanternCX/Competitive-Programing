#include<bits/stdc++.h>

using namespace std;
void sol(int n){
	string s;
	cin >> s;
	int cnt = 0;
	for(auto ch : s){
		cnt += ch == 'S' ? 1 : -1;
		if(cnt > n || cnt < 0){
			cout << "NO\n";
			return;
		}
	}
	cout << (cnt  == 0 ? "YES\n" : "NO\n");
}

int main(){
	int t = 1;
	cin >> t;
	int n;
	cin >> n;
	while(t--){
		sol(n);
	}
	return 0;
}