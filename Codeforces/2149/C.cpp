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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    map<int, int> cnt;
    for (auto x : a) {
        cnt[x] ++;
    }
    int temp = 0;
    for (int i = 0; i < k; i++) {
        temp += cnt[i] == 0;
    }
    debug(a);
    debug(temp);
    cout << temp + max((cnt[k] - temp), 0) << '\n';
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