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
    while(cin >> n){
        if(n == 0){
            return;
        }
        vector<int> a(n);
        for(auto &x : a){
            cin >> x;
        }
        vector<int> mp = {100, 50, 10, 5, 2, 1};
        int ans = 0;
        for(auto &x : a){
            for(auto v : mp){
                ans += x / v;
                x %= v;
            }
        }
        cout << ans << '\n';
    }
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