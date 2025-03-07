#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
	int n;
	cin >> n;
	vector<ll> u(n), v(n), w(n);
	map<ll, ll> mp;
	for(int i = 0; i < n; i++){
		vector<int> arr(3);
		for(auto &x : arr){
			cin >> x;
		}
		sort(arr.begin(), arr.end());
		do{
			ll x = (arr[0] - arr[1]) / arr[2];
			if(x >= 0 && (arr[0] - arr[1]) % arr[2] == 0){
				mp[x]++;
			}
		}while(next_permutation(arr.begin(), arr.end()));
	}
	for(auto p : mp){
		if(p.second == n){
			cout << abs(p.first) << '\n';
			return;
		}
	}
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
     cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
x = (b - c) / a

3 1 10
14 2 4

*/