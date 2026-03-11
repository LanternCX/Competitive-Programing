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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x;
    }
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        if(pre[i] < m && a[i - 1] >= b[pre[i]]){
            pre[i]++;
        }
    }

    if(pre[n] >= m){
        cout << 0 << "\n";
        return;
    }

    vector<int> suf(n  +2, 0);
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1];
        if(suf[i] < m && a[i - 1] >= b[m - 1 - suf[i]]){
            suf[i]++;
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 1; i <= n + 1; i++){
        int x = pre[i - 1];
        int y = suf[i];
        if(x + y >= m - 1 && x < m){
            ans = min(ans, b[x]);
        }
    }
    if(ans == LLONG_MAX) {
        ans = -1;
    }
    cout << ans << "\n";
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
 * 等于说可以跳过 b 中的某个数字
 * 
 * 怎么判断跳过之后是否可行？
 * 
 * 模拟在前前面里有多少贡献满足要求
 * 末尾也是
 */