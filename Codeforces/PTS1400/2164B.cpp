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
    vector<int> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[j] % a[i]) % 2 == 0) {
                cout << a[i] << " " << a[j] << "\n";
                return;
            }
        }
    }
    cout << -1 << '\n';
}
void test() {
    int n = 100;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((j % i) % 2 == 0) {
                debug(i, j, j % i);
            }
        }
    }
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
 * a % b = 2k
 * 
 * a = nb + 2k
 * 
 */