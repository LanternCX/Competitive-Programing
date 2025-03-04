#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
	int n;
	cin >> n;
	vector<int> arr(n), vis(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[arr[i] - 1] = 1;
		}
	}
	int cnt = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			cnt++;
			ans.push_back(i + 1);
		}
	}
	cout << cnt << '\n';
	for(int x : ans){
		cout << x << ' ';
	}
	cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}