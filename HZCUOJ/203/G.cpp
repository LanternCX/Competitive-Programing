#include <bits/stdc++.h> 

using namespace std;
using ll = long long;
void sol(){
	while(1){
		int n;
		cin >> n;
		if(n == 0){
			return;
		}
		vector<int> a(n), b(n);
		for(auto &x : a){
			cin  >> x;
		}
		
		for(auto &x : b){
			cin >> x;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int cnt = 0;
		for(int i = 0, j = 0; i < n; i++){
			if(a[i] > b[j]){
				j++;
				cnt++;
			}
		}
		cout << (cnt > (n * 1.0 / 2) ? "YES" : "NO") << '\n';
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