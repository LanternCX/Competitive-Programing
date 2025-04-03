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
    vector<int> p(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    vector<int> idx(n + 1);
    for(int i = 1; i <= n; i++){
        idx[p[i]] = i;
    }
    debug(idx);
    vector<int> vis(n + 1);
    int ans = 0;
    // x 是 1 开头的
    auto dfs = [&](auto&& dfs, int x) -> void {
        debug(x);
        if(p[x] != x && !vis[x]){
            ans += 1;
            vis[x] = 1;
            dfs(dfs, idx[x]);
        }else if(vis[x]){
            ans += 0;
        }else if(p[x] == x){
            ans += 1;
        }
    };
    for(int i = 1; i <= n; i++){
        dfs(dfs, b[i]);
        cout << ans << ' ';
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
 * b[i] = p[b[i]]
 * 那么对答案贡献就是 1
 * 如果不是 那么对答案贡献就是 2
 * 
 * 相当于交换？
 * 
 * 4 3 1 2 7 5 6
 * 1 2 3 4 5 6 7
 * 
 * 0 3 1 2 7 5 6
 * 1 2 3 4 7 5 6
 * 
 * 1 2 3 4 5 6 7
 * 
 * 每一位贡献多少其实是 dfs 的层数
 * 然后累加贡献
 */