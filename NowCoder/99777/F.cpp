#include <bits/stdc++.h>

using namespace std;

void sol(){
	string s, r;
	int k;
	cin >> k >> s >> r;
	int lens = s.length();
	int lenr = r.length();
	int ans = 0;
	for(int i = 0; i < lens - lenr + 1; i++){
		string temp = s.substr(i, lenr);
		int cnt = 0;
		for(int j = 0; j < lenr; j++){
			if(temp[j] != r[j]){
				cnt++;
			}
		}
		if(cnt == k){
			ans++;			
		}
	}
	cout << ans << '\n';
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}