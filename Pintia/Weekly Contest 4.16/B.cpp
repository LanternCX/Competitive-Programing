#include<bits/stdc++.h>

using namespace std;

void sol(){
	int n;
	cin >> n;
	vector<string> a(n);
	set<string> s;
	for(auto x :a){
		cin >>x;
		s.insert(x);
	}
	cout << s.size() <<'\n';
	int cnt = 0;
	for(auto x : s){
		cout << x;
		cnt++;
		if(cnt < s.size()){
			cout << ' ';
		}
	} 
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
		if(t!= 0){
			cout << '\n';
		}
	}
	return 0; 
} 