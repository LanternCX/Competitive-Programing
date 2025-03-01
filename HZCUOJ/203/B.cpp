#include <bits/stdc++.h> 

using namespace std;
void sol(){
	int a, b;
	cin >> a >> b;
	if(a < b){
		cout << "lose\n"; 
	}else if(a > b){
		cout << "win\n";
	}else{
		cout << "same\n";
	}
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