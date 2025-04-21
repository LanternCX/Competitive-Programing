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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int idx = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            idx = i;
        }
    }
    if (idx == -1) {
        cout << -1 << "\n";
        return;
    }
    
    int x = a[idx];
    debug(idx);
    a.erase(a.begin() + idx);
    a.erase(a.begin() + idx - 1);
    for (int i = 1; i < n - 2; i++) {
        if (abs(a[i] - a[i - 1]) < 2 * x) {
            cout << x << ' ' << x << ' ' << a[i - 1] << ' ' << a[i] << '\n';
            return;
        }
    }
    cout << -1 << "\n";
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
 * 2 * n + a > b
 * 2 * n > |b - a|
 */