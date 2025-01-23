
#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> fa;
    int n;
    DSU(int size) {
        n = size;
        fa = vector<int>(n);
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
                res += i;
            }
        }
        return res;
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}