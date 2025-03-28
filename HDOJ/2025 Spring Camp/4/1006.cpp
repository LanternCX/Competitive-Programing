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
#define int long long
template<typename T> struct Fenwick{
    int n;
    vector<T> tr;

    Fenwick(int size) : n(size), tr(size + 1){}

    int lowbit(int x){
        return x & -x;
    }

    void update(int idx, T val){
        for(int i = idx; i <= n; i += lowbit(i)){
            tr[i] += val;
        }
    }

    T query(int idx){
        T res = T();
        for(int i = idx; i > 0; i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
using BIT = Fenwick<ll>;
void sol(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    BIT bit(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        bit.update(i, x);
    }
    
    ll ans = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        debug(bit.query(i));
    }
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            int det = y - arr[x];
            // arr[x] + y - arr[x]
            arr[x] = y;
            bit.update(x, det);
        }
        if(op == 2){
            cnt++;
            int l, r;
            cin >> l >> r;
            ll res = bit.query(r) / 100 - bit.query(l - 1) / 100;
            ans ^= res * (cnt);
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