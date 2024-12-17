#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	ll a,b;
};
int main(){
	int n;
	cin >> n;
	vector<node> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i].a >> arr[i].b;
	}
	sort(arr.begin(), arr.end(), [](node a, node b) -> int {
		if(a.a == b.a){
			return a.b > b.b;
		}
		return a.a < b.a;
	});
	
	vector<ll> pre(n + 1); 
	pre[0] = arr[0].b;
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + arr[i].b;
	}
	
	ll maxpart2 = -1e15, ans = -1e15;
	for(int i = 1; i <= n; i++){
		maxpart2 = max(maxpart2, arr[i].a - pre[i - 1]);
		ll part1 = pre[i] - arr[i].a;
		ans = max(ans, part1 + maxpart2);
	}
	cout << ans;
	return 0;
}
/**
sum = pre[r] - pre[l - 1]
ans = sum - (maxa - mina)
ans = pre[r] - pre[l - 1] - (maxa - mina)
= (pre[r] - maxa) + (mina - pre[l - 1])
= (pre[i] - arr[i].a) + max(mina - pre[l - 1]);
= part2 + part1
*/ 