#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int cnt[N + 10];
void dfs(int begin, vector<int> tree){
    cnt[begin]++;
    if(tree[begin] != begin){
        dfs(tree[begin], tree);
        
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> tree(n);
    for(int i = 1; i < n; i++){
        cin >> tree[i];
    }
    int q;
    cin >> q;
    while(q--){
        for(int i = 0; i <= n; i++){
            cnt[i] = 0;
        }
        int m;
        cin >> m;

        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            dfs(x, tree);
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(cnt[i] == m){
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}