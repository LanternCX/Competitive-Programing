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
    vector<int> a(n), b(n);
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x;
    }
    int cnt = 0;
    int mx = INT_MIN, mn = INT_MAX;
    int sum = 0;
    int is = 0;
    for(int i = 0; i < n; i++){
        if (b[i] == -1) {
            cnt++;
            mx = max(mx, a[i]);
            mn = min(mn, a[i] + k);
        } else {
            ll temp = a[i] + b[i];
            if (!is) {
                is = true;
                sum = temp;
            } else if (sum != temp) {
                cout << 0 << '\n';
                return;
            }
        }
    }

    ll ans = 0;
    if (!is) {
        if (mx <= mn) {
            cout << mn - mx + 1 << '\n';
            return;
        }else{
            cout << 0 << '\n';
            return;
        }
    }else if (cnt == 0){
        cout << 1 << '\n';
        return;
    }else if(mx <= sum && sum <= mn){
        cout << 1 << '\n';
        return;
    }else{
        cout << 0 << '\n';
        return;
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