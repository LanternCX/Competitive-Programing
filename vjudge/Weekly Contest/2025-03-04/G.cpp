#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
struct query {
    int l, r, id;
};
const ll N = 2e5;
vector<ll> cnt(N, 0);
template <typename T, typename Q>
struct Mo {
    vector<T> a;
    const int n;
    int l, r;
    Q ans;

    Mo(vector<T> a) : a(a), n(a.size()), l(0), r(0), ans(0) {}

    void add(int x) {
        int e = a[x];
        ans += cnt[e] * (cnt[e] - 1) / 2;
        cnt[e]++;
    }

    void insert_left(int x) {}

    void insert_right(int x) {}

    void del(int x) {
        int e = a[x];
        cnt[e]--;
        ans -= cnt[e] * (cnt[e] - 1) / 2;
    }

    void erase_left(int x) {}

    void erase_right(int x) {}

    auto solve(int len, vector<query> que) {
        vector<Q> res(que.size());
        sort(begin(que), end(que), [&](query p, query q) {
            int A = (p.l) / len, B = (q.l) / len;
            if (A != B) return A < B;
            if (A % 2 == 0) return p.r < q.r;
            return p.r > q.r;
        });
        for (auto &e : que) {
            while (e.l < l) add(--l);
            while (r < e.r) add(r++);
            while (l < e.l) del(l++);
            while (e.r < r) del(--r);
            res[e.id] = ans;
        }
        return res;
    }
};

void sol(){
    ll n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
        x--;
    }
	vector<query> que(q);
    for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--;
        que[i] = {l, r, i};
	}
    Mo<int, ll> mo(arr);
    auto ans = mo.solve(500, que);
    for(auto x : ans){
        cout << x << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}