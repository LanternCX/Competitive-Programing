#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int fa[N + 10];
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = fa[root(y)];
}
bool query(int x, int y){
    return root(x) == root(y);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i < N; i++){
        fa[i] = i;
    }
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            merge(x, y);
        }
        if(op == 2){
            cout << (query(x, y) ? "Y\n" : "N\n");
        }
    }
    return 0;
}