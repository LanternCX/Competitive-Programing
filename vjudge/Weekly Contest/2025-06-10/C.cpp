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
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    vector<ll> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    debug(pre);
    int ans = 0;
    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > pre[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
 * 1 1 2 3
 * 2
 * 4 3
 * 
 * 5 1 3 2 1
 * 
 * 1 1 2 3 5
 * 
 * 1 1 1 2 4
 * 
 * dp[i] 表示第 i 个数能否被构造出来
 * 
 * 那么怎么转移呢？
 * 从前面转移
 * 
 * dp[i][j] 表示到第 i 个数为止能否构造出 j
 * 
 * dp[i - 1][j - c[i]]
 */