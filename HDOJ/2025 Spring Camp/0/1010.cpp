#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void sol(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i] = abs(arr[i]);
	}
	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		sum += arr[i];
		ans += sum;
	}
	cout << ans << '\n';
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