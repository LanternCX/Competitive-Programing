#include <bits/stdc++.h>
using namespace std;
const int N = 5e3;
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
struct node{
    int sta, dst, w;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    sort(edges.begin(), edges.end(), [](node a, node b) -> bool {
        return a.w < b.w;
    });
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
    int cnt = 0;
    vector<node> ans;
    for(node nd : edges){
        if(!query(nd.dst, nd.sta)){
            merge(nd.dst, nd.sta);
            ans.push_back(nd);
            cnt++;
        }
        if(cnt == n - 1){
            break;
        }
    }
    int sum = 0;
    for(node nd : ans){
        sum += nd.w;
    }
    if(cnt == n - 1){
        cout << sum;
    }else {
        cout << "orz";
    }
    return 0;
}