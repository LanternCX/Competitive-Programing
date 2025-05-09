#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define int ll

void sol(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
    	cin >> b[i];
	}
	vector<int> c(n + 1);
	for(int i = 1; i <= n; i++){
		c[i] = a[i] + b[i];
	}
	
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i]; 
	}
	int ans = 0;
	int len = 1;
	for(int i = 1; i <= n; i++){
		if(c[i] == c[i - 1]){
			len++;
			ans = max((pre[i] - pre[i - len])* len, ans);
		}else{
			len = 1;
			ans = max(a[i], ans);
		}
	}
	cout << ans << '\n';
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