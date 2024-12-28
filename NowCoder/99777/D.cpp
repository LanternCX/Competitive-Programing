#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;
int main(){
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	vector<int> cnt(N);
	vector<vector<int>> pre;
	pre.push_back(cnt);
	for(int i = 1; i <= n; i++){
		cnt[arr[i - 1]]++;
		pre.push_back(cnt);
//		for(int i = 1; i <= 9; i++){
//			cout << i << ' ';
//		}
//		cout << endl;
//		for(auto x : pre){
//			for(int j = 1; j < 10; j++){
//				cout << x[j] << ' ';
//			} 
//			cout << '\n';
//		}
//		cout << '\n';
	}

	while(q--){
		int l, r;
		cin >> l >> r;
		vector<int> ans(2);
		int idx = 0;
		for(int i = 1; i <= N; i++){
			int cnt = pre[r][i] - pre[l - 1][i];
			if(cnt == 1){
				ans[idx] = i;
				idx++;
			}
		}
		if(ans[0] > ans[1]){
			cout << ans[1] << ' ' << ans[0];
		}else{
			cout << ans[0] << ' ' << ans[1]; 
		}
		cout << '\n';
	}
	return 0;
}
/**
 * To Be Done
 */