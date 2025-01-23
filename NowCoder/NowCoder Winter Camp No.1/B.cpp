#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(g[i].size() > 2){
            cout << -1;
            return 0;
        }
        if(g[i].size() == 1){
            ans.push_back(i);
        }
    }
    cout << ans[0] + 1 << ' ' << ans[1] + 1;
    return 0;
}