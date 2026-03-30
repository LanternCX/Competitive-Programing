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
    int n, d;
    cin >> n >> d;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    deque<int> q;
    
    auto calc = [&](int x) {
        int need = x;
        // op1: use
        while (need > 0) {
            int now = q.front();
            q.pop_front();
            if (need >= now) {
                need -= now;
            } else {
                now -= need;
                need = 0;
                q.push_front(now);
            }
        }

        // op2: clear
        while (q.size() > d) {
            q.pop_front();
        }
    };

    for (int i = 0; i < n; i++) {
        q.push_back(a[i]);
        calc(b[i]);
    }

    ll ans = 0;
    while (!q.empty()) {
        ans += q.front();
        q.pop_front();
    }

    cout << ans << '\n';
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
 * 7 2 3
 * 1 3 2
 * 
 */