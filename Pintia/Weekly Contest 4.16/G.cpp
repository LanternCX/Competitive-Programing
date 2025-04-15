#include<bits/stdc++.h>

using namespace std;

void sol(int t){
	int k;
	cin >> k;
	string s;
	int cnt = 0;
	while(cin >> s){
		if(s == "End"){
			return;
		}
		if(cnt == k){
			cout << s << '\n';
			cnt %= k;
			continue;
		}
		cnt++;
		if(s == "ChuiZi"){
			cout << "Bu" << '\n'; 
		}
		if(s == "JianDao"){
			cout << "ChuiZi" << '\n';
		}
		if(s == "Bu"){
			cout << "JianDao" << '\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol(t);
	}
	return 0; 
} 