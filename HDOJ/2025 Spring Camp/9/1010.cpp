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
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    debug(g);

    int ans = 1;
    for(int i = n; i > 0; i--){
        auto & arr = g[i];
        for(auto &x : arr){
            if(g[x].count(i)){
                g[x].erase(g[x].find(i));
            }
            if(g[x].size() == 0 && x != 0){
                ans = 0;
                break;
            }
        }
        arr.clear();
    }
    cout << ans << '\n';
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