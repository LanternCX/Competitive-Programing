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
struct node {
    int v, p;
};
void sol(){
    int n, m;
    cin >> n >> m;

    vector<node> main(m + 1);
    vector<vector<node>> ext(m + 1);
    vector<int> is(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) {
            main[i] = {v, p};
            is[i] = 1;
        } else {
            ext[q].push_back({v, p});
        }
    }

    vector<int> dp(n+1, 0);
    
    for (int i = 1; i <= m; i++) {
        if (!is[i]) continue;
        int v0 = main[i].v;
        int p0 = main[i].p;
        int v1 = 0, p1 = 0;
        int v2 = 0, p2 = 0;
        if (ext[i].size() >= 1) {
            v1 = ext[i][0].v;
            p1 = ext[i][0].p;
        }
        if (ext[i].size() >= 2) {
            v2 = ext[i][1].v;
            p2 = ext[i][1].p;
        }
        for (int j = n; j >= 0; j--) {
            if (j >= v0)
                dp[j] = max(dp[j], dp[j - v0] + v0 * p0);
            if (v1 > 0 && j >= v0 + v1)
                dp[j] = max(dp[j], dp[j - v0 - v1] + v0 * p0 + v1 * p1);
            if (v2 > 0 && j >= v0 + v2)
                dp[j] = max(dp[j], dp[j - v0 - v2] + v0 * p0 + v2 * p2);
            if (v1 > 0 && v2 > 0 && j >= v0 + v1 + v2)
                dp[j] = max(dp[j], dp[j - v0 - v1 - v2] + v0 * p0 + v1 * p1 + v2 * p2);
        }
    }

    cout << dp[n];
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