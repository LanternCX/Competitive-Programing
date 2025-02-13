#include <bits/stdc++.h>
using namespace std;
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
        for(int i = 1; i < n; i++){
            if(fa[i] == i){
                res++;
            }
        }
        return res;
    }
};
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    DSU dsu(m * n + 1);
    int k;
    cin >> k;
    while(k--){
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }
    cout << dsu.root();
    return 0;
}