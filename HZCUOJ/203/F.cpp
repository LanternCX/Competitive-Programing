#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
void sol(){
	int l, n;
	cin >> l >> n;
	vector<vector<long long> > ans(2);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		ans[0].push_back(max(abs(l - x), x));
		ans[1].push_back(min(abs(l - x), x));
	}
	cout << *max_element(ans[1].begin(), ans[1].end()) << ' ' << *max_element(ans[0].begin(), ans[0].end()) << '\n';
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