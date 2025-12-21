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
    int n, h;
    cin >> n >> h;
    int t = 0;
    int l = h, u = h;
    vector<int> T(n), L(n), U(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i] >> L[i] >> U[i];
    }
    for (int i = 0; i < n; i++) {
        int ti = T[i], li = L[i], ui = U[i];
        int dh = ti - t;
        
        l -= dh;
        u += dh;

        t = ti;

        l = max(l, li);
        u = min(u, ui);

        if (l > u) {
            debug(ti, dh, l, u);
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * 当前位置到达目标位置一共三种情况
 * h>u h<l l<h<u
 * 
 * t1 h1
 * t2 h2
 * 
 * h1 到达的 h2 的范围 = h1 +- (t2 - t1)
 * 
 * h1 的范围 max(l, h0 - (t0 - t1)) - min(u, h0 + (t0 - t1))
 * 
 * 也就是说 维护一个可能的范围
 */