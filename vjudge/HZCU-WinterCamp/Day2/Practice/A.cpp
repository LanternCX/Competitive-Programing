#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int mp[N + 10][N + 10];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mp[i][j] << ' ';
        }
        cout << '\n';
    }
    for(auto &arr : g){
        sort(arr.begin(), arr.end());
    }
    for(auto arr : g){
        cout << arr.size() << ' ';
        for(int x : arr){
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}