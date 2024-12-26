#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int pre[N + 10];
int root(int x){
   return pre[x] = pre[x] == x ? x : root(pre[x]); 
}
void merge(int x, int y){
    pre[root(x)] = pre[root(y)]; 
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        pre[i] = i;
    }
    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1){
            merge(x, y);
        }
        if(z == 2){
            cout << (root(x) == root(y) ? "Y" : "N") << '\n';
        }
    }
    return 0;
}