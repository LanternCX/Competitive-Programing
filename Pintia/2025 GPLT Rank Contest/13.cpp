#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct DSU {
	int n;
	vector<int> fa;
	DSU(int x) {
		n = x;
		fa = vector<int>(x);
		for (int i = 0; i < n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		return fa[x] = fa[x] == x ? x : find(fa[x]);
	}
	int query(int a, int b) {
		return find(a) == find(b);
	}
	void merge(int a, int b) {
		fa[find(b)] = fa[find(a)];
		
	}
}; 

int main() {
	int n;
	cin >> n;
	map<int, vector<int>> mp;
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int c = stoi(s.substr(0, s.length() - 1));
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			for (auto k : mp[x]) {
				dsu.merge(k, i);
			}
			mp[x].push_back(i);
		}
	}
	map<int, int> cnt;
	for (int x : dsu.fa) {
		cnt[dsu.find(x)]++;
	}
	cout << cnt.size() << '\n';
	vector<int> ans;
	for (auto p : cnt) {
		ans.push_back(p.second);
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i == ans.size() - 1]; 
	}
	return 0;
}