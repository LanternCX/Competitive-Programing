#include<bits/stdc++.h> 
using namespace std;
pair<int, int> pii;
struct node{
	int l, r, id;
};
void sol(){
	int n;
	cin >> n;
	vector<node> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].l >> arr[i].r;
		arr[i].id = i;
	}
	sort(arr.begin(), arr.end(), [&](node a, node b){
		return a.l < b.l;
	});
	vector<int> ans(n, 2);
	int l = arr[0].l, r = arr[0].r;
	ans[arr[0].id] = 1;
	int cnt = 1;
	for(int i = 1; i < n; i++){
		node now = arr[i];
		if(now.l <= r){
			l = now.l, r = max(now.r, r);
			ans[now.id] = 1;
			cnt++;
			continue;
		}else{
			break;
		}
	}
	
	if(cnt == n){
		cout << -1 << '\n';
		return;
	}
	
	for(auto x : ans){
		cout << x << ' ';
	}
	cout << '\n';
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