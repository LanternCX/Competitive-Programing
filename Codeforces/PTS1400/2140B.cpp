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
    int x;
    cin >> x;
    int y = x * 8;
    cout << y << '\n';
    debug(stoll(to_string(x) + to_string(y)) % (x + y));
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
 * (x * 10 + y) /  x + y
 * x * 9 / (x + y) + 1
 * 
 * (x * (1en - 1) + x + y) / xy
 * x * 1en - 1 / (x + y) = 1
 * x * 1en - 1 = x + y
 */