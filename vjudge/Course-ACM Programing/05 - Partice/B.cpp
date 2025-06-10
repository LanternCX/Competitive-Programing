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
void sol(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }

        sort(a.begin(), a.end(), [](pii a, pii b){
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        vector<bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            cnt++;
            auto [l, w] = a[i];
            vis[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (!vis[j] && a[j].first >= l && a[j].second >= w) {
                    l = a[j].first;
                    w = a[j].second;
                    vis[j] = 1;
                }
            }
        }
        cout << cnt << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}