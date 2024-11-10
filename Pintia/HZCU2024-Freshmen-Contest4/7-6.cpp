#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[1000][1000];
void sol(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		string temp = s.substr(i, 3);
		if(temp == "cat"){
			cnt++;
		}
	}
	if(cnt > 2){
		cout << "No" << '\n';
		return;
	}
	if(cnt == 2){
		cout << "Yes" << '\n';
		return;
	}
	for(int i = 0; i < s.size(); i++){
		string temp = s.substr(i, 3);
		if(temp == "?at" || temp == "c?t" || temp == "ca?" 
			|| temp == "??t" || temp == "c??" || temp == "?a?" || temp == "???"){
			cout << "Yes" << '\n';
			return;
		}
	}
	cout << "No\n";
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