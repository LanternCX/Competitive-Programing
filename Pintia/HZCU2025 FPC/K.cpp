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
    int n, m, k;
    cin >> n >> k >> m;
    vector<double> sc;
    while (n--) {
        vector<int> arr(k);
        ll sum = 0;
        for (auto &x : arr) {
            cin >> x;
            sum += x;
        }
        int mx = *max_element(arr.begin(), arr.end());
        int mn = *min_element(arr.begin(), arr.end());
        // ll sum = accumulate(arr.begin(), arr.end(), 0);
        sc.push_back((sum - mx - mn) * 1.0 / (k - 2));
    }
    sort(sc.begin(), sc.end(), greater<double>());
    for (int i = m - 1; i >= 0; i--) {
        if (i != m - 1) {
            cout << ' ';
        }
        cout << sc[i];
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(3);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}