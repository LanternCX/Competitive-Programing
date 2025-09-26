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
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());
    debug(a);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i - 1, r = n - i;
        if (k >= abs(l - r) - 1) {
            ans++;
        }
    }
    
    for (int i = 1; i < n; i++) {
        int l = i, r = n - i;
        if (k >= abs(l - r)) {
            ans += a[i + 1] - a[i] - 1;
        } 
    }
    cout << ans << '\n';
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
 * 考虑每一位的贡献
 * 
 * 因为取了绝对值
 * 实际上关闭任意酒吧对答案的贡献都是独立的
 * 
 * 每间酒吧的顺序
 * 
 * 首先考虑 k = 0 的情况
 * 相邻的情况之间可以转移
 * 
 * 
 */