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
    vector<ll> s(n + 1);
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i - 1];
    }
    debug(s);
    multiset<ll> sum;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            sum.insert(s[j] - s[i - 1]);
        }
    }
    debug(sum);
    ull ans = LONG_LONG_MAX;
    for(int i = 1; i < n; i++){
        for(int j = i; j <= n; j++){
            sum.erase(sum.find(s[j] - s[i - 1]));
        }
        for(int j = 1; j <= i; j++){
            ll k = s[i] - s[j - 1];
            auto p = sum.lower_bound(k);
            if(p != sum.end()){
                ans = min(ans, (ull) abs(*p - k));
            }
            if(p != sum.begin()){
                p--;
                ans = min(ans, (ull) abs(*p - k));
            }
        }
    }
    cout << ans;
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