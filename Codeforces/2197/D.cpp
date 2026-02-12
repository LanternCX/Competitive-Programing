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
void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> idx(n + 1);

    for (int i = 1; i <= n; i++) {
        if (a[i] <= n) {
            idx[a[i]].push_back(i);
        }
    }

    int ans = 0;

    for (int x = 1; x <= n; x++) {
        if (idx[x].empty()) {
            continue;
        }

        for (ll y = 1; x * y <= n; y++) {
            if (idx[y].empty()) {
                continue;
            }

            int diff = x * y;

            if (idx[x].size() <= idx[y].size()) {
                for (int i : idx[x]) {
                    if (i + diff <= n && a[i + diff] == y) {
                        ans++;
                    }
                }
            } else {
                for (int j : idx[y]) {
                    if (j - diff >= 1 && a[j - diff] == x) {
                        ans++;
                    }
                }
            }
        }
    }
    
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * nlogn
 * 对于每一个下标 i 可以查询有多少合法的 j
 * ai * aj = j - i
 * 
 * aj = j / ai - i / ai
 * 
 * 好像不对
 * 
 * 似乎可以暴力优化？
 * 
 * 首先 j - i 最大为 n - 1
 * 那么 大于 n 的 ai 都可以忽略
 * 同样 乘积 > n 的数对也可以忽略
 * 
 * nsqrt(n)?
 * 
 * 对每一个值查询另外一个值似乎就可以了
 */