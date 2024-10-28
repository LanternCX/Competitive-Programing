#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> diff(n);
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		diff[x] += 1;
		diff[y + 1] -= 1;
	}
	
	vector<int> ans(n);
	ans[0] = diff[0];
	for(int i = 1; i < n; i++){
		ans[i] = ans[i - 1] + diff[i];
	}
	sort(ans.begin(), ans.end());
	cout << ans[n / 2];
	return 0;
}