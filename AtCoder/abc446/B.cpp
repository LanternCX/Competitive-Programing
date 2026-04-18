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
    vector<int> vis(m);

    auto calc = [&](vector<int> arr) {
        int ans = 0;
        for (auto x : arr) {
            if (vis[x]) {
                continue;
            } else {
                vis[x] = 1;
                ans = x + 1;
                break;
            }
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        int ans = 0;

        vector<int> arr(l);

        for (auto &x : arr) {
            cin >> x;
            x--;
        }

        cout << calc(arr) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}