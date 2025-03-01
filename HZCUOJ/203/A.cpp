#include <bits/stdc++.h> 

using namespace std;
void sol(){
	while(1){
		int n;
		cin >> n;
		if(n == 0){
			return;
		}
		if(n == 1){
			int x;
			cin >> x;
			cout << x * 6 + 5 << '\n'; 
			continue;
		}
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int ans = arr[0] * 6 + 5;
		for(int i = 1; i < n; i++){
			if(arr[i] > arr[i - 1]){
				ans += 6 * (arr[i] - arr[i - 1]);
			}else if(arr[i] < arr[i - 1]){
				ans += 4 * (arr[i - 1] - arr[i]);
			}
			ans += 5;
		}
		cout << ans << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t--){
		sol();
	}
	return 0;
} 