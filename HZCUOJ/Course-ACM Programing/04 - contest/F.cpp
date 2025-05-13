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
    int x, y;
};
struct edge{
    double u, v, w;
};
void sol(){
    int n;
    cin >> n;
    vector<node> a(n);
    for(auto &[x, y] : a){
        cin >> x >> y;
    }
    auto dis = [&](node a, node b){
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    };
    vector<edge> ed;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            auto x = a[i], y = a[j];
            double d = dis(x, y);
            if(d >= 10 && d <= 1000){
                ed.push_back({(double)i, (double)j, d});
            }
        }
    }
    sort(ed.begin(), ed.end(), [&](edge a, edge b) {
        return a.w < b.w;
    });
    
    int cnt = 0;
    double ans = 0;
    DSU dsu(n);
    for (auto [x, y, w] : ed) {
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

    if(cnt != n - 1){
        cout << "oh!\n";
    }else{
        cout << ans * 100 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(1);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}