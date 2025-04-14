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
struct node{
    int u, v, w;
};
struct DSU{
    int n;
    vector<int> fa;
    DSU(int siz){
        n = siz;
        fa = vector<int>(n);
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    }

    int find(int x){
        return fa[x] = fa[x] == x ? fa[x] : find(fa[x]);
    }

    int query(int x, int y){
        return find(x) == find(y);
    }

    void merge(int x, int y){
        fa[find(x)] = fa[find(y)];
    }
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<node> arr;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        arr.push_back({u, v, w});
    }
    DSU dsu(n + 1);
    sort(arr.begin(), arr.end(), [&](node a, node b){
        return a.w < b.w;
    });
    int cnt = 0;
    ll ans = 0;
    for(auto [u, v, w] : arr){
        if(dsu.query(u, v)){
            continue;
        }
        dsu.merge(u, v);
        cnt++;
        ans += w;
        if(cnt == n - 1){
            break;
        }
    }
    if(cnt != n - 1){
        cout << "orz\n";
        return;
    }
    cout << ans << '\n';
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