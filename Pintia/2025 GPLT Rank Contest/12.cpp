#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define int long long

struct node {
	int l, r, c;
};

signed main() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (auto &s : arr) {
		cin >> s;
	}
	// l, r
	map<string, node> mp;
	map<int, int> right;
	
	int center = 0;
	
	auto calc = [&](string s) {
//		cout << s << ' ';
		stack<char> st;
		int r = 0, l = 0, c = 0;
		for (auto ch : s) {
			if (ch == '(') {
				st.push(ch);
			}
			if (ch == ')') {
				if (!st.empty()) {
					st.pop();
					c++;	
				} else {
					r++;
				}
			}
		}
		l = st.size();
		mp[s].l = l;
		mp[s].r = r;
		mp[s].c = c;
		if (l == 0 && r != 0) {
			right[r]++;
		}
		if (l != 0 && r == 0) {

		}
		if (l == 0 && r == 0) {
			center++;
		}
	};
	
	for (auto s : arr) {
		calc(s);
	}
	
	ll ans = 0;
	for (auto s : arr) {
		node nd = mp[s];
		if (nd.l != 0 && nd.r == 0) {
			int k = right[nd.l];
			ans += k;
		}
	}
	
	ans += center * center;
	

	cout << ans;
	
	return 0;
}
/**
每个串两种，一种左失配，一种右失配
每一个左失配串和右失配串匹配 
*/