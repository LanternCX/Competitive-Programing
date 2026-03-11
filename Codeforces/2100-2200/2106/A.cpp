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
#define int long long
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto ch : s){
        cnt += ch == '1';
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            ans += cnt - 1;
        }else{
            ans += cnt + 1;
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}