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
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = (a[i] <= k ? 1 : 0);
    }
    if (n < 3) {
        cout << "NO\n";
        return;
    }

    vector<int> pre(n+1, 0), suf(n+2, 0);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + b[i];
    }
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i+1] + b[i];
    } 

    vector<bool> l(n+1, 0), r(n+2, 0);
    for(int i = 1; i <= n; i++){
        if (pre[i] * 2 >= i) l[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        int len = n - i + 1;
        if (suf[i] * 2 >= len) r[i] = 1;
    }

    vector<int> nxt(n+2, n + 5), prv(n+2, 0);
    for(int i = n; i >= 1; i--){
        nxt[i] = b[i] ? i : nxt[i+1];
    }

    for(int i = 1; i <= n; i++){
        prv[i] = b[i] ? i : (i > 1 ? prv[i-1] : 0);
    }  

    bool ok = 0;
    for(int i = 1; i <= n-1 && !ok; i++) {
        if (!l[i]) continue;
        int idx = nxt[i+1];
        if (idx <= n){
            ok = 1;
            break;
        }
    }

    for(int i = 1; i <= n-2 && !ok; i++){
        if (l[i] && r[i+2]) {
            ok = 1;
            break;
        }
    }

    for(int i = 2; i <= n-1 && !ok; i++){
        if (!r[i+1]){
            continue;
        }
        if (prv[i] >= 1){
            ok = 1;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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
