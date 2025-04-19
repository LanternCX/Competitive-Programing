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

#define int long long
struct edge{
    int v, p, q;
};
void sol(){
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    // vector<vector<int>> mp(n, vector<int>(n));
    unordered_map<int, unordered_map<int, int>> mp;
    for(int i = 0; i < n - 1; i++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;
        g[u].push_back({v, x, y});
        g[v].push_back({u, y, x});
        mp[u][v] = x;
        mp[v][u] = y;
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<int> dp(n);
    auto dfs = [&](auto&& dfs, int nd, int pre) -> int {
        for(auto [v, p, q] : g[nd]){
            if(v == pre){
                continue;
            }
            int res = max(dfs(dfs, v, nd), 0LL);
            if(pre != -1){
                dp[nd] += max(mp[pre][nd], 0LL);
            }
            dp[nd] += res + p + q;
        }
        return dp[nd];
    };
    dfs(dfs, s, -1);
    debug(dp);
    stack<int> st;
    auto find = [&](auto&& find, int nd, int pre) -> int {
        for(auto [v, p, q] : g[nd]){
            if(v == pre){
                continue;
            }
            st.push(v);
            if(v == t){
                return 1;
            }
            if(find(find, v, nd)){
                return 1;
            }else{
                st.pop();
            }
        }
        return 0;
    };
    find(find, s, -1);
    int ans = 0;
    vector<int> path;
    while(!st.empty()){
        path.push_back(st.top());
        st.pop();
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size() - 1; i++){
        int res;
        if(i == 0){
            res = mp[path[i]][path[i + 1]];
            ans += res;
            for(auto ed : g[path[i]]){
                if(ed.v == path[i + 1]){
                    continue;
                }
                int det = max(dp[ed.v] + mp[path[i]][ed.v] + mp[ed.v][path[i]], 0LL);
                ans += det;
                debug(det, ed.v);
            }
        }else{
            res = mp[path[i]][path[i + 1]];
            ans += res;
            for(auto ed : g[path[i]]){
                if(ed.v == path[i + 1] || ed.v == path[i - 1]){
                    continue;
                }
                int det = max(dp[ed.v] + mp[path[i]][ed.v] + mp[ed.v][path[i]], 0LL);
                ans += det;
                debug(det, ed.v);
            }
        }
        debug(res);
    }
    ans += max(dp[t], 0LL);
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * s 到 t 的路径一定要走不能往回
 * 
 * 对于其他路径
 * 
 * 
 * 例如 1 2, 1 3, 2 3
 * 节点 1 到 2 获得的最大可能贡献取决于 2 -> 3 的最大贡献加上 1 -> 2 的最大贡献
 * 
 * 所以走到每个节点的最大贡献其实是可以从当前节点的下一层转移的
 * 
 * 写一个 dfs + dp
 * 
 * 定义 dp[i] 为走到 i 节点再回到根节点的最大贡献
 * dp[n] = sum{i 节点的下一层的节点的所有正贡献}
 */