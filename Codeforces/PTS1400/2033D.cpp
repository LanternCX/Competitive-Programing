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
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    map<ll, int> idx;
    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + a[i];
    }
    int ans = 0;
    debug(a);
    int pre = -1;
    for(int i = 0; i <= n; i++){
        if(idx.count(a[i])){
            if(idx[a[i]] >= pre){
                ans++;
                pre = i;
            }
        }
        idx[a[i]] = i;
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
/**
 * sum = pre[r] - pre[l - 1];
 */