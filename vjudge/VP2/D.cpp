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
    ull n, m, k;
    cin >> n >> m >> k;
    vector<vector<ull>> mp(n + 1, vector<ull>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mp[i][j];
        }
    }
    
    vector<vector<ull>> sum(n + 1, vector<ull>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
        }
    }
    debug(sum);
    auto calc = [&](int i1, int j1, int i2, int j2){
        ull s = sum[i2][j2] - sum[i1 - 1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];
        return s <= k;
    };
    ull cnt = 0;
    for (int up = 1; up <= n; up++) {
        for (int down = up; down <= n; down++) {
            for (int l = 1, r = 1; r <= m; r++) {
                while (l <= r && !calc(up, l, down, r)) {
                    l++;
                }
                if (l <= r){
                    cnt += r - l + 1;
                }
            }
        }
    }
    cout << cnt;
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