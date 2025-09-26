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
    int n;
    cin >> n;
    
    vector<vector<int>> mp(2, vector<int>(n));
    ll ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }

    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans += max(mp[0][i], mp[1][i]);
        mx = max(mx, min(mp[0][i], mp[1][i]));
    }

    ans += mx;
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}