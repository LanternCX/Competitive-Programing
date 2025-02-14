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
const int p = 1e9 + 7;
const int N = 1e5 + 5;
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        ll res = binpow(a, b / 2) % p;
        return (res * res) % p;
    }else{
        ll res = binpow(a, b - 1) % p;
        return ((a % p) * res) % p;
    }
}
void sol(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l, r;
    cin >> l >> r;
    vector<ll> fac(N), infac(N);

    fac[0] = infac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % p;
		infac[i] = binpow(fac[i], p - 2);
	}

    // c(n, m) = n! / m! * (n - m)!
    auto c = [&](int n, int m) -> ll {
        if (n < m || n < 0 || m < 0){
            return 0;
        }
	    return fac[n] * infac[n - m] % p * infac[m] % p;
    };

    vector<int> vis(n), cnt(n);
    auto work = [&](int x){
        if(!vis[x]){
            vis[x] = 1;
            for(int i = l - 1; i <= r - 1; i++){
                cnt[x] = (cnt[x] + c(x, i)) % p;
            }
        }
        return cnt[x];
    };

    ll ans = 0;
    for(auto arr : g){
        ans += work(arr.size());
        ans %= p;
    }
    cout << ans % p;
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
/**
 * n! = 1 * 2 * ... * n
 * m! = 1 * 2 * ... * m
 * (n - m)! = 1 * 2 * ... * (n - m)!
 * n! / m! * (n - m)! = (1 * 2 * ... * n) / (1 * 2 * ... * m) * (1 * 2 * ... * (n - m)!)
 * = (m + 1) * ... * n / 1 * ... * (n - m)!
 */