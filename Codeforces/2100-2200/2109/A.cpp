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
    for (int &x : a) {
        cin >> x;
    }

    vector<int> cnt(2);
    for (int x : a) {
        cnt[x]++;
    }

    if (cnt[1] > n - 1) {
        cout << "YES\n";
        return;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0 && a[i-1] == 0) {
            ans = 1;
            break;
        }
    }

    cout << (ans ? "YES\n" : "NO\n");
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