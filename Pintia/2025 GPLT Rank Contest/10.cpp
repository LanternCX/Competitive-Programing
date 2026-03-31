#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct node {
	string name;
	int id;
	float avg;
	int sc;
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<node> a;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		int k;
		cin >> k;
		vector<int> arr(k);
		map<int, int> cnt;
		for (auto &x : arr) {
			cin >> x;
			cnt[x]++;
		}
		int sum = 0;
		for (auto p : cnt) {
			sum += p.second;
		}
		a.push_back({name, i, (float) sum / cnt.size(), cnt.size()});
	}
	
	sort(a.begin(), a.end(), [](node a, node b) -> bool {
		if (a.sc == b.sc) {
			return a.avg < b.avg;
		} 	
		return a.sc > b.sc;
	});
	
	vector<string> ans;
	for (int i = 0; i < a.size() && i < 3; i++) {
		ans.push_back(a[i].name);
	}
	
	while (ans.size() < 3) {
		ans.push_back("-");
	}
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
	}
	cout << "\n";

	return 0;
}