#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll binpow(int a, int n){
	if(n  == 1){
		return a;
	}
	if(n == 0){
		return 1;
	}
	if(n % 2 == 0){
		ll res = binpow(a, n / 2);
		return res * res;
	}
	if(n % 2 == 1){
		ll res = binpow(a, n - 1);
		return a * res;
	}
	return -1;
}
#define int long long
void sol(int t){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int ans = 1 << n;
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			auto ch = s[i];
			if(ch == 'y'){
				ans -= 1 << (n - i - 1);
			}
		}
		cout << ans << '\n';
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol(t);
	}
	return 0; 
} 