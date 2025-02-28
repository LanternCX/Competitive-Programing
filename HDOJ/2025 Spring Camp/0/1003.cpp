#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}

void sol(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n), c(n), det(n);
	for(auto &x : a){
		cin >> x;
	}
	for(auto &x : b){
		cin >> x;
	}
	for(auto &x : c){
		cin >> x;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for(int i = 0; i < n; i++){
		det[i] = c[i] - b[i];
	}
	
	ll sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++){
		sum1 += a[i];
		sum2 += det[i];
	}
	cout << sum2 / sum1 << '\n';
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
	}
	return 0;
}
/**
ax = c - b

*/