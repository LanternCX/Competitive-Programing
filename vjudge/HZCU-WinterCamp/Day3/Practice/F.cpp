#include <bits/stdc++.h>
using namespace std;
const int N = 100;
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
    int from, to, w;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i < N; i++){
        fa[i] = i;
    }
    int n, k;
    cin >> n >> k;
    vector<node> arr(k);
    for(int i = 0; i < k; i++){
        cin >> arr[i].from >> arr[i].to >> arr[i].w;
    }
    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.w < b.w;
    });
    vector<node> ans;
    for(node nd : arr){
        if(query(nd.from, nd.to)){
            continue;
        }
        ans.push_back(nd);
        merge(nd.from, nd.to);
    }
    int sum = 0;
    for(node nd : arr){
        sum += nd.w;
    }
    for(node nd : ans){
        sum -= nd.w;
    }
    cout << sum;
    return 0;
}