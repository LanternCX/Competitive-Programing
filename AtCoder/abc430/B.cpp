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
    int m, n;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    set<ull> st;
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            ull num = 0;
            int idx = 0;
            for (int x = i; x < i + m; x++) {
                for (int y = j; y < j + m; y++) {
                    num += (1 << idx++) * (mp[x][y] == '#');
                }
            }
            st.insert(num);
        }
    }
    cout << st.size() << '\n';
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