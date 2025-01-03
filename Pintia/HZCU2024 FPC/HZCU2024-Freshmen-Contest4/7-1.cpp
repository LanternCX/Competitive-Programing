#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	for(char ch : s){
		if(ch == '1'){
			ans++;
		}
	}
	cout << ans; 
}