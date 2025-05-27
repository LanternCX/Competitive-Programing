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
    int id;
};
void sol(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(n);
    vector<int> fa(n);
    auto bfs = [&](){
        queue<int> q;
        vector<int> vis(n);
        q.push(0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            vis[now] = 1;
            for (auto x : g[now]) {
                if (x == now || vis[x]) {
                    continue;
                }
                q.push(x);
                fa[x] = now;
            }
        }
    };
    debug(fa);
    auto dfs = [&](auto &&dfs, int now, int d, int res, int mx) {
        if (d % 2 == 0) {
            res += v[now];
        } else {
            res -= v[now];
        }
        mx = max(res, mx);
        if (now == 0) {
            return mx;
        } else {
            return dfs(dfs, fa[now], d + 1, res, mx);
        }
    };
    bfs();
    for (int i = 0; i < n; i++) {
        ans[i] = dfs(dfs, 0, 0, 0, INT_MIN);
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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
/**
 * 对于奇数深度和偶数深度分别讨论
 * 从顶层 bfs 下来
 * 按照规则 + -
 * 然后如果是偶数就直接乘一个 -1
 * 
 * 好像直接暴力？
 */