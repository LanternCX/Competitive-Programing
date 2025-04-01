#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e3;
ll binpow(ll a, ll b){
	if(b == 0){
		return 1;
	}
	if(b == 1){
		return a;
	}
	if(b % 2 == 0){
		ll res = binpow(a, b / 2);
		return res * res;
	}
	if(b % 2 == 1){
		ll res = binpow(a, b - 1);
		return res * a; 
	}
	return 0;
}
#define int long long
ll work(ll x){
	int cnt = 0;
	vector<int> s;
	s.push_back(0);
	while(x){
		cnt++;
		s.push_back(x % 10);
		x /= 10; 
	}
	reverse(s.begin() + 1, s.end());
	ll res = 0;
	for(int i = 2; i <= cnt; i++){
		for(int j = 1; j <= 9; j++){
			if(i == cnt && j == s[1]){
				break;
			}
			res += binpow(j, i - 1);
		}
	}
	
	for(int i = 2; i <= cnt; i++){
		for(int j = 0; j < min(s[1], s[i]); j++){
			res += binpow(s[1], cnt - i);
		}
		if(s[i] < s[1] && i == cnt) {
			res += binpow(s[1], cnt - i);
		}
		if(s[i] >= s[1]){
			break;
		}
	}
	return res;
}
void sol(){
	ll l, r;
	cin >> l >> r;
	cout << work(r) - work(l - 1) << '\n';
}
signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}
/**
对于一个最高位 x
后面所有的位 x < 0 
例如 5
5444
4 * (10^1, 10^2, 10^3)
*/