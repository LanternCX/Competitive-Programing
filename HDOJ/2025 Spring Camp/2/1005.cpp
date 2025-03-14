#include<bits/stdc++.h>

using namespace std;
using ll = long long;
void sol(){
	ll n, k;
	cin >> n >> k;
	if(k % 2 == 1){
		cout << 0 << '\n';
		return;
	}
	ll a = n / k;
	ll b = n / k + 1;
	ll cnt = n % k;
	
	if(cnt < k / 2){
		cout << cnt * a * b + (k / 2 - cnt) * a * a << '\n';
	}
	
	if(cnt >= k / 2){
		cnt = cnt - k / 2;
		cout << cnt * b * b + (k / 2 - cnt) * a * b << '\n'; 
	}
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
/**
和 第 0 根重合的有 (n / k)
和 第 0 根垂直的有 (n / (k / 2)) - (n / k)
总共有 k / 2 组

	vector<int> arr(k);
	for(int i = 0; i < n; i++){
		arr[i % k]++;
	}
	int ans = 0;
	for(int i = 0; i < k / 2; i++){
		ans += arr[i] * arr[k / 2 + i];
	}
	化简为 O(1) 
	
	arr[i] = n / k + ((n % k) > i);
	arr[k / 2 + i] = n / k + ((n % k) > (k / 2 + i));
*/