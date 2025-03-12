#include<bits/stdc++.h> 
using namespace std;
pair<int, int> pii;
void sol(){
	int n;
	cin >> n;
	int mx = 0, my = 0;
	while(n--){
		char op;
		cin >> op;
		int x, y;
		cin >> x >> y;
		if(x > y){
			swap(x, y);
		}
		if(op == '+'){
			mx = max(mx, x);
			my = max(my, y);
		}
		if(op == '?'){
			if(x > y){
				swap(x, y);
			}
			if(x >= mx && y >= my){
				cout << "YES\n";
			}else{
				cout << "NO\n"; 
			}
		}
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