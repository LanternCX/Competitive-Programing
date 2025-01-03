#include<bits/stdc++.h>
using namespace std;
void sol(){
	string n;
	cin >> n;
	if(n.substr(0, 2) == "10"){
		if(n.length() > 3 && n[2] - '0' >= 1){
			cout << "YES\n";
			return;
		}else if(n[2] - '0' >= 2){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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