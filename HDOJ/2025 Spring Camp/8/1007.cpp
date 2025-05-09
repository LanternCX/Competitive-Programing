#include <bits/stdc++.h>

using namespace std;
#define int long long
struct node{
	int p, q;
};
using ll  = long long;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
int lcm (int a, int b){
	return a * b / gcd(a, b);
}

void sol(){
	int n, m;
	cin >> n >> m;
	vector<node> a(n), b(m);
	vector<int> x = {0}, y = {0};
	int s = 1;
	for(auto &nd : a){
		int p, q;
		cin >> p >> q;
		nd = {p, q};
		s = lcm(s, q);
	}
	for(auto &nd : b){
		int p, q;
		cin >> p >> q;
		nd = {p, q};
		s = lcm(s, q);
	}
	for(auto nd : a){
		int p = nd.p;
		int q = nd.q;
		x.push_back(p * (s / q) + x[x.size() - 1]); 
	}
	for(auto nd : b){
		int p = nd.p;
		int q = nd.q;
		y.push_back(p * (s / q) + y[y.size() - 1]); 
	}
//	cout << s << '\n';
//	for(auto g : x){
//		cout << g << ' ';
//	}
//	cout << '\n';
//	for(auto g : y){
//		cout << g << ' ';
//	}
//	cout << '\n';
	int cnt = 0;
	x.erase(x.end() - 1);
	y.erase(y.end() - 1);
	for(auto g : x){
		int it = *lower_bound(y.begin(), y.end(), g);
		cnt += it == g;
	}
	cout << cnt << '\n';
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
		sol();
	} 
	return 0;
} 