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
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<int> cnt(50);
    for(auto x : a){
        for(int i = 0; i < 30; i++){
            cnt[i] += (x >> i) & 1;
            if(x << i == 0){
                break;
            }
        }
    }
    int ans = 0;
    for(auto x : a){
        int sum = 0;
        for(int i = 0; i < 30; i++){
            if((x >> i) & 1){
                sum += (n - cnt[i]) * (1LL << i);
            }else{
                sum += (cnt[i]) * (1LL << i);
            }
        }
        ans = max(sum, ans);
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