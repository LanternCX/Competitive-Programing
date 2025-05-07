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
    int mx = *max_element(a.begin(), a.end());
    vector<int> ans(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == mx){
            ans[i] = 2;
            cnt++;
        }else{
            ans[i] = 1;
        }
    }
    if(cnt == n){
        cout << "No\n";
        return;
    }else{
        cout << "Yes\n";
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
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