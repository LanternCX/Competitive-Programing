#include <bits/stdc++.h> 

using namespace std;
using ll = long long;
void sol(){
	while(1){
		string s;
		cin >> s;
		if(s == "-1"){
			return;
		}
		ll sum = 0;
		for(auto ch : s){
			sum += ch - '0';
		}
		while(sum > 9){
			sum = 0;
			
			for(auto ch : s){
				sum += ch - '0';
			}
			s = to_string(sum);
		}
		cout << sum << '\n'; 
	}
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