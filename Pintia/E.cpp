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
    int r, c;
    cin >> r >> c;
    map<int, pii> mp;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            mp[x] = {i, j};
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        auto [x1, y1] = mp[x];
        auto [x2, y2] = mp[y];
        int res = (abs(x1 - x2) == 1 && y1 == y2) || ((x1 == x2) && abs(y1 - y2) == 1);
        cout << (res ? "yes\n" : "no\n");
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