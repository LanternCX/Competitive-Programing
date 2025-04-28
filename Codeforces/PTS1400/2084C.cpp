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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
    
    vector<pii> ans;
    auto work = [&](int i, int j){
        if (i == j) {
            return;
        }
        swap(a[i], a[j]);
        swap(p[a[i]], p[a[j]]);
        swap(b[i], b[j]);
        ans.push_back({i, j});
    };

    int x = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == b[i]) {
			if (n % 2 == 0 || x) {
				cout << "-1\n";
				return;
			}
			x = i;
		} else if (b[p[b[i]]] != a[i]) {
			cout << "-1\n";
			return;
		}
	}

	if (n & 1) {
		work(x, (n + 1) / 2);
	}
	for (int i = 1; i <= n / 2; ++i) {
		work(p[b[i]], n - i + 1);
	}
    
    debug(a, b);
    cout << ans.size() << '\n';
    for(auto [i, j] : ans){
        cout << i << ' ' << j << '\n';
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
 * 1 2 3 4
 * 4 3 2 1
 * 
 * first 为 x 的对需要放在 second 为 x 的位置的对称位置
 * 
 * 先统计 first 为 x 的位置 和 second 为 x 的位置
 * 只统计 n / 2
 * 
 * 然后进行 dfs 交换
 * 
 * 对每个位置 dfs 到尽头
 * 复杂度 O(n)
 * 
 * 对于相等的情况 奇数 1 个偶数没有
 * 在中心线
 * 
 * 对于不相等的情况
 * a[i] 排到 b[i] 出现的位置 p[i]
 * 
 * 
 * 2 5 1 3 4
 * 3 5 4 2 1
 * 
 * 2 1 5 3 4 
 * 3 4 5 2 1
 */