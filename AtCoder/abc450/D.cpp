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
    ll k;
    cin >> k;
    vector<ll> a(n);
    ll mxg = 0;
    for (auto &x : a) {
        cin >> x;
        mxg = max(mxg, x);
    }

    vector<pair<ll, ll>> mx;
    multiset<ll> mn;

    for (auto x : a) {
        ll mnv = mxg - (mxg - x) % k;
        ll mxv = mnv + k;
        mx.push_back({mnv, mxv});
        mn.insert(mnv);
    }

    sort(mx.begin(), mx.end());

    ll ans = *mn.rbegin() - *mn.begin();

    for (auto p : mx) {
        mn.erase(mn.find(p.first)); 
        mn.insert(p.second);
        ans = min(ans, *mn.rbegin() - *mn.begin());
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * 对每一个数求一个最大值和一个最小值(最小值就是自己)，维护成有序序列。
 * 然后对每个 max 到 min 中查询
 * 记得 erase 掉 max 自己对应的 min
 */