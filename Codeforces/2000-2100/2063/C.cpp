#include <bits/stdc++.h>
using namespace std;
struct node{
    int id;
    vector<int> arr;
    int size, is = 0;
};
const int N = 2 * 1e5;
int fa[N + 10];
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = root(y);
}
bool query(int x, int y){
    return root(x) == root(y);
}
void sol(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
    vector<node> g(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].arr.push_back(v);
        g[v].arr.push_back(u);
    }
    for(int i = 0; i < n; i++){
        g[i].size = g[i].arr.size();
        g[i].id = i;
    }
    vector<node> f = g;
    sort(f.begin(), f.end(), [](node a, node b) -> int {
        return a.arr.size() > b.arr.size();
    });
    vector<int> ids;
    node a = f[0];
    ids.push_back(a.id);
    g[a.id].is = 1;
    for(int x : a.arr){
        g[x].size -= 1;
    }
    f = g;
    sort(f.begin(), f.end(), [](node a, node b) -> int {
        return a.size > b.size;
    });
    int id = f[0].is ? f[1].id : f[0].id;
    ids.push_back(id);
    g[id].is = 1;
    for(int i = 0; i < n; i++){
        for(int x : g[i].arr){
            if(g[x].is == 0 && g[i].is == 0){
                merge(i, x);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(root(i) == i && g[i].is == 0){
            ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * To be done
 */