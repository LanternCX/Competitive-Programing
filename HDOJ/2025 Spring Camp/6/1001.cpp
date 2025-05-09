#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define int ll

void sol(){
    int k;
    cin >> k;
    int a, b, c;
    cin >> a >> b >> c;
	int ans = k;
	if(a <= k){
		ans = min(k - (a), ans);
	}
	if(b <= k){
		ans = min(k - (b), ans);
	}
	if(c <= k){
		ans = min(k - (c), ans);
	}
	if(a + b <= k){
		ans = min(k - (a + b), ans);
	}
	if(a + c <= k){
		ans = min(k - (a + c), ans);
	}
	if(c + b <= k){
		ans = min(k - (c + b), ans);
	}
	if(a + b + c <= k){
		ans = min(k - (a + b + c), ans);
	}
	cout << max(ans, 0LL) << '\n';
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