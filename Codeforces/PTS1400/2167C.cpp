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
    vector<int> cnt(2);
    for (auto &x : a) {
        cin >> x;
        cnt[x % 2]++;
    }
    if (cnt[0] == n || cnt[1] == n) {
        for (auto x : a) {
            cout << x << ' ';
        } 
    } else {
        sort(a.begin(), a.end());
        for (auto x : a) {
            cout << x << ' ';
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