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
    ll sum = 0;
    int cnt = 0;
    for(auto &x : a){
        cin >> x;
        sum += x;
        cnt += x % 2;
    }
    cnt -= 1;
    cnt = max(cnt, 0);
    debug(cnt, sum);
    cout << (sum - cnt) * (sum - cnt) + cnt << '\n';
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