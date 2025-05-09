#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define int ll

void sol(){
    int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &x : arr){
		cin >> x;
	} 
	string s;
	cin >> s;
	// r a
	vector<int> a, b;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R'){
			a.push_back(arr[i]);
		}else{
			b.push_back(arr[i]);
		}
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	vector<int> ans = {0, 0};
	if(a.size() <= b.size()){
		for(int i = 0; i < a.size(); i++){
			ans[0] += a[i];
			ans[1] += b[i];
		}
	}
	if(a.size() > b.size()){
		for(int i = 0; i < b.size(); i++){
			ans[0] += a[i];
			ans[1] += b[i];
		}
		ans[0] += a[b.size()];
	}
	cout << ans[0] + ans[1] << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
a 先 b 后
如果 a 先跳完 b 就要比 a 少一个
如果 b 先跳完 a 和 b 一样多
如果 a 和 b 长度一样那么是 a 先跳完 

1
6
1 1 4 5 1 4
RBBRRR
*/