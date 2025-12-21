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
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for (auto [x, arr] : mp) {
        double sum = accumulate(arr.begin(), arr.end(), 0);
        cout << sum / arr.size() << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}