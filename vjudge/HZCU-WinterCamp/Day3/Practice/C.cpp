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
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    vector<int> ans(n + 10), temp(n + 1);
    for(int i = 0; i < m; i++){
        int op;
        cin >> op;
        if(op == 1){
            int a, b;
            cin >> a >> b;
            if(query(a, b)){
                continue;
            }
            for(int i = 1; i <= n; i++){
                ans[i] += temp[root(i)];
            }
            for(int i = 1; i <= n; i++){
                temp[i] = 0;
            }

            merge(a, b);
        }
        if(op == 2){
            int p, t;
            cin >> p >> t;
            temp[root(p)] += t;
        }
    }
    for(int i = 1; i <= n; i++){
        ans[i] += temp[root(i)];
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i]<< ' ';
    }
    return 0;
}