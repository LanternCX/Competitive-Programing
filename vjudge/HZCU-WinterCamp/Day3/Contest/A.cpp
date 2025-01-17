#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int fa1[N + 10];
int fa2[N + 10];
using ll = long long;
int root1(int x){
    return fa1[x] = fa1[x] == x ? x : root1(fa1[x]);
}
void merge1(int x, int y){
    fa1[root1(x)] = fa1[root1(y)];
}
int query1(int x, int y){
    return root1(x) == root1(y); 
}
int root2(int x){
    return fa2[x] = fa2[x] == x ? x : root2(fa2[x]);
}
void merge2(int x, int y){
    fa2[root2(x)] = fa2[root2(y)];
}
int query2(int x, int y){
    return root2(x) == root2(y); 
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    for(int i = 1; i <= n; i++){
        fa1[i] = i;
    }
     for(int i = 1; i <= m; i++){
        fa2[i] = i;
    }
    for(int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;
        merge1(x, y);
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        merge2(-x, -y);
    }
    ll cnt1 = 0;
    ll cnt2 = 0;
    for(int i = 1; i <= n; i++){
        if(query1(fa1[i], 1)){
            cnt1++;
        }
    }
    for(int i = 1; i <= m; i++){
        if(query2(fa2[i], 1)){
            cnt2++;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << fa1[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 1; i <= m; i++){
    //     cout << fa2[i] << ' ';
    // }
    // cout << '\n';
    cout << min(cnt1, cnt2);
    return 0;
}