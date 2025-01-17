#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
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
void sol(int n){
    int m;
    cin >> m;
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        if(query(x, y)){
            continue;
        }
        merge(x, y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] == i){
            ans++;
        }
    }
    cout << ans - 1 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        sol(n);
    }
    return 0;
}