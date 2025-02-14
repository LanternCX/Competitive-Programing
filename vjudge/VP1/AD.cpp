#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int sum = 0, cnt, x=1;
	for (int i = 1; i <= 60; i++) {
		while (1) {
			cnt = 0;
			for (int j = 1; j <= x; j++){
				if (x % j == 0){
					cnt++;
                }
            }
			if (cnt >= i){
				break;
            }
			x++;
		}
		sum += x;
	}
	cout << sum << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}