#include<bits/stdc++.h> 
using namespace std;
void sol(){
	string s;
	cin >> s;
	int n  = s.length();
	int ans = 0;
	int l = -1, r = -1;
	for(int i = 0; i < n; i++){
		if(s[i] == '[' && l == -1){
			l = i;
		}
		if(s[i] == ']'){
			r = i;
		}
	}
	if(l == -1 || r == -1 || l > r){
		cout << -1 << '\n';
		return;
	}
	
	string tag = s.substr(l + 1, r - l - 1);
//	cout << tag << ' ';
	l = -1, r = -1;
	for(int i = 0; i < tag.length(); i++){
		if(tag[i] == ':' && l == -1){
			l = i;
		}
		if(tag[i] == ':'){
			r = i;
		}
	}
	
	if(l == -1 || r == -1 || l == r){
		cout << -1 << '\n';
		return;
	}
	
	tag = tag.substr(l + 1, r - l - 1);

	int cnt = 0;
	for(char ch : tag){
		cnt += ch != '|';
	}
//	cout << tag << '\n';
	cout << tag.length() + 4 - cnt << '\n';
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}