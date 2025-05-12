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
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    
    vector<vector<int>> div(2);
    
    for(int i = 0; i < n; i++){
        div[i % 2].push_back(a[i]);
    }

    for(auto &arr : div){
        sort(arr.begin(), arr.end());
    }

    for(int i = 0; i < n; i++){
        cout << div[i % 2][i / 2] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 操作有什么性质?
 * 两次交换可以抵消
 * 
 * 
 * 1 2 3 4 5 6
 * 3 4 1 2 5 6
 * 3 2 4 4
 */