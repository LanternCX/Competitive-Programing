#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> diff(n + 10);
	vector<int> a(n + 10);
	for(int i = 1; i <= m; i++){
		int x, y, k;
		cin >> x >> y >> k;
		diff[x] += k;
		diff[y + 1] -= k;
	}
	
	vector<int> ans(n + 10);
	for(int i = 1; i <= n; i++){
		ans[i] = ans[i - 1] + diff[i];
	}
	cout << ans[1] << ' ';
	for(int i = 2; i <= n; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}