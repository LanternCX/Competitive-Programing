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
    
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++){
        fa[i] = i;
    }
    vector<node> arr(m);
    for(int i = 0; i < m; i++){
        int x, y, l;
        cin >> x >> y >> l;
        arr[i] = {x, y, l};
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.w < b.w;
    });
    vector<node> ans;
    int tag = 0;
    for(node nd : arr){
        if(!query(nd.from, nd.to)){
            merge(nd.from, nd.to);
            ans.push_back(nd);
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(fa[i] == i){
                    cnt++;
                }
            }
            if(cnt == k){
                tag = 1;
                break;
            }
        }
    }
    int sum = 0;
    for(node nd : ans){
        sum += nd.w;
    }

    if(tag){
        cout << sum;
    }else{
        // cout << cnt << '\n';
        cout << "No Answer";
    }
    return 0;
}