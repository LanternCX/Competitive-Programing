#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int fa[N + 10];
using ll = long long;
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = fa[root(y)];
}
int query(int x, int y){
    return root(x) == root(y); 
}
struct node{
    int from, to, w;
};

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
    vector<node> arr(m);
    for(int i = 0; i < m; i++){
        int x, y, t;
        cin >> x >> y >> t;
        arr[i] = {x, y, t};
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.w < b.w;
    });
    vector<node> ans;
    int cnt = 0;
    for(node nd : arr){
        if(!query(nd.from, nd.to)){
            merge(nd.from, nd.to);
            ans.push_back(nd);
            cnt++;
        }
        if(cnt == n - 1){
            break;
        }
    }
    int mx = 0;
    for(node nd : ans){
        mx = max(nd.w, mx);
    }
    if(cnt == n - 1){
        cout << mx;
    }else{
        // cout << cnt << '\n';
        cout << -1;
    }
    return 0;
}