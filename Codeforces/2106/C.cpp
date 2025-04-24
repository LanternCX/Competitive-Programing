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
    ll k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool is = false;
    bool ok = true;
    ll is_x = 0;
    ll mn = LLONG_MIN, mx = LLONG_MAX;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            cnt++;
            mn  = max(mn,  a[i]);
            mx = min(mx, a[i] + k);
        } else {
            ll sum = a[i] + b[i];
            if (!is) {
                is = true;
                is_x = sum;
            } else if (sum != is_x) {
                ok = false;
                break;
            }
        }
    }

    ll ans = 0;
    if (!ok) {
        ans = 0;
    } else if (!is) {
        if (mn <= mx) {
            ans = mx - mn + 1;
        } else {
            ans = 0;
        }
    } else {
        if (cnt == 0) {
            ans = 1;
        } else {
            if (mn <= is_x && is_x <= mx) {
                ans = 1;
            } else {
                ans = 0;
            }
        }
    }

    cout << ans << "\n";
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
 * b = 
 */