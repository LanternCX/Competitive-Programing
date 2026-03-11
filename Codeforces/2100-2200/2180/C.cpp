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
    cout << n << ' ';
    k -= 1;
    vector<int> a(k);
    int bit = 0;
    for (bit = 0; bit < 1e2; bit++) {
        if ((n >> bit) <= 0) {
            break;
        } 
    }
    debug(bit, k);
    if (k % 2 == 1) {
        for (int i = 0; i < bit; i++) {
            if (((n >> bit) % 2) == 1) {
                for (auto &x : a) {
                    x ^= (1 << bit);
                }
            }
            if (((n >> bit) % 2) == 0) {
                for (int i = 0; i < k - 1; i++) {
                    a[i] ^= (1 << bit);
                }
            }
            debug(a);
        }
    }
    if (k % 2 == 0) {
        for (int i = 0; i < bit; i++) {
            if (((n >> bit) % 2) == 0) {
                for (auto &x : a) {
                    x ^= (1 << bit);
                }
            }
            if (((n >> bit) % 2) == 1) {
                for (int i = 0; i < k - 1; i++) {
                    a[i] ^= (1 << bit);
                }
            }
            debug(a);
        }
    }
    for (auto x : a) {
        cout << x << ' ';
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
 * to be done
 */