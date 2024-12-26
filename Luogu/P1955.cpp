#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 2;
struct node{
    int i, j, e;
};
int fa[N + 10];
int arr[N + 10];
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}

void merge(int x, int y){
    x = root(x);
    y = root(y);
    fa[x] = y;
}
void sol(){
    int n;
    cin >> n;
    vector<node> op;
    for(int i = 0; i <= N; i++){
        fa[i] = i;
    }
    int ans = 1;
    int idx = 1;
    while(n--){
        int i, j, e;
        cin >> i >> j >> e;
        arr[idx++] = i;
        arr[idx++] = j;
        op.push_back({i, j, e});
    }
    sort(arr, arr + idx + 1);
    // auto it = unique(arr.begin(), arr.end());
    sort(op.begin(), op.end(), [](node a, node b) -> bool {
        return a.e > b.e;
    });

    for(node nd : op){
        int a = lower_bound(arr + 1 , arr + idx + 1, nd.i) - (arr + 1);
        int b = lower_bound(arr + 1 , arr + idx + 1, nd.j) - (arr + 1);
        if(nd.e == 1){
            merge(a, b);
        }
        if(nd.e == 0){
            if(root(a) == root(b)){
                ans = 0;
                break;
            }
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}