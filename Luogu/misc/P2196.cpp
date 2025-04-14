#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cin >> mp[i][j];
            mp[j][i] = mp[i][j];
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    auto dfs = [&](int now){
        
    };
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 每个点都可以选择挖或者不挖
 * 
 * 暴力的话应该是 20 * 20
 * 
 * 那其实直接回溯就好了
 */