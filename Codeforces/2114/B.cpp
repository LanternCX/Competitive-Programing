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
    string s;
    cin >> s;
    vector<int> cnt(2);
    for (char ch : s) {
        cnt[ch - '0']++;
    }
    
    cnt[0] -= n / 2 - k;
    cnt[1] -= n / 2 - k;
    if (cnt[0] < 0 || cnt[1] < 0) {
        cout << "NO\n";
        return;
    }
    if (cnt[0] / 2 + cnt[1] / 2 == k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
/**
 * 首先构造不相等
 */