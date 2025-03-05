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
struct node{
    ll l, r;
    ll id;
};
const ll N = 2e5;
void sol(){
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    vector<node> que(q);
    for(ll i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        que[i] = {l, r, i};
    }
    ll len = 450;
    sort(que.begin(), que.end(), [&](node x, node y) {
        if(x.l / len != y.l / len){
			return x.l / len < y.l / len;
        }
		if(x.l / len % 2 == 0){
            return x.r < y.r;
        }else{
            return x.r > y.r;
        }
    });

    ll l = 0, r = -1;
    ll now = 0;
    vector<int> t(N + 10);
    auto add = [&](ll x){
        t[x]++;
        if(t[x] >= 3){
            now += (t[x] - 1) * (t[x] - 2) / 2;
        }
    };

    auto del = [&](ll x) {
		t[x]--;
		if (t[x] >= 2){
            now -= t[x] * (t[x] - 1) / 2;
        }
	};

    vector<ll> ans(q);
    for (auto [ql, qr, id] : que) {
		while (r < qr) add(arr[++r]);
		while (l > ql) add(arr[--l]);
		while (r > qr) del(arr[r--]);
		while (l < ql) del(arr[l++]);
		ans[id] = now;
	}
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