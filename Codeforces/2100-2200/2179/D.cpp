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
    for (int i = n; i >= 0; i--) {
        ll suf = (1 << i) - 1;

        int sufcnt = __builtin_popcount(suf);
        int precnt = n - sufcnt - 1;
        debug(suf);
        debug(sufcnt, precnt);
        if (precnt <= 0) {
            cout << suf << ' ';
            continue;
        }
        for (int j = 0; j <= ((1 << (precnt)) - 1); j++) {
            ll pre = j << (sufcnt + 1);
            ll res = pre ^ suf;
            debug(j, pre, suf, res);
            cout << res << ' ';
        }
    }
    cout << '\n';
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
 * 总 n 位
 * 后缀 sufcnt 位
 * 前缀 n - sufcnt - 1
 * 3 11 3
 * 1 01 1
 * 0 00 0
 * 2 10 0
 * 
 * 1111 
 * 
 * 111 7
 * 
 * 011 3
 * 
 * 001 1
 * 101 5
 * 
 * 000
 * 010
 * 100
 * 110
 */