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
const string tag = "_-";
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    debug(s.length());
    vector<ll> cnt(2);
    ll ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '_'){
            cnt[0]++;
        }
        if(s[i] == '-'){
            cnt[1]++;
        }
    }
    cout << cnt[0] * ((cnt[1] + 1LL) / 2LL) * (cnt[1] / 2LL) << '\n';
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
 * _-_-_-_-_-
 */