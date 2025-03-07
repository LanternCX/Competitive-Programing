#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
void sol() {
	ll n;
	cin >> n;
	if(n == 1) {
		cout << 0 << '\n';
		return;
	}
	ll x = n / 2;
	ll ans = ((x) % mod * (x + 1) % mod) % mod;
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
/**
n * (a1 + an) / n
n / 2
2
*/