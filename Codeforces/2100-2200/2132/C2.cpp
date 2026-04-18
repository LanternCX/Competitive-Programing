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
const int N = 40;
vector<ll> p(N);
void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i-1] * 3LL;
    }
    
}
void sol() {
    ll n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 3LL * n << '\n';
        return;
    }
    vector<ll> cnt(N, 0);
    cnt[0] = n;
    ll tot = n;
    ll ext = 0;

    for (int i = 0; i + 1 < N && tot > k; i++) {
        if (cnt[i] < 3) continue;
        ll acc = cnt[i] / 3;
        ll need = (tot - k + 1) / 2;
        ll use = min(acc, need);
        if (use == 0) continue;
        cnt[i] -= use * 3;
        cnt[i + 1] += use;
        tot -= use * 2;
        ext += use * p[i];
        if (cnt[i] >= 3 && tot > k) {
            i--;
        }
    }

    if (tot > k) {
        cout << -1 << '\n';
    } else {
        cout << 3LL * n + ext << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}
