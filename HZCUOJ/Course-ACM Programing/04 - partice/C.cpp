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
struct DSU {
    vector<int> fa;
    int n;
    DSU(int size): n(size), fa(size) {
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    bool query(int x, int y){
        return find(x) == find(y);
    }

    int root(void){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == i){
                res++;
            }
        }
        return res;
    }
};
struct node {
    int x, y, w;
};
void sol(){
    int m, n;
    while (cin >> n >> m) {
        if (m == 0 && n == 0) {
            return;
        }
        ll sum = 0;
        vector<node> a(m);
        for (auto &nd : a) {
            auto & [x, y, w] = nd;
            cin >> x >> y >> w;
            sum += w;
        }

        DSU dsu(n);
        
        sort(a.begin(), a.end(), [&](node a, node b) {
            return a.w < b.w;
        });
        
        int cnt = 0;
        ll ans = 0;
        for (auto [x, y, w] : a) {
            if (cnt == n - 1) {
                break;
            }
            if (dsu.query(x, y)) {
               continue; 
            }
            dsu.merge(x, y);
            cnt++;
            ans += w;
        }
        cout << sum - ans << '\n';
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