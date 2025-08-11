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
    vector<ll> S(n), T(n);
    for (auto &x : S) {
        cin >> x;
    }
    for (auto &x : T) {
        cin >> x;
    }

    if (k == 0) {
        sort(S.begin(), S.end());
        sort(T.begin(), T.end());
        cout << (S == T ? "YES\n" : "NO\n");
        return;
    }

    map<ll, ll> cnt1, cnt2;
        
    for (ll x : S) {
        ll r = x % k;
        if (r < 0) {
            r += k;
        }
        cnt1[r]++;
    }

    for (ll x : T) {
        ll r = x % k;
        if (r < 0) {
            r += k;
        }
        cnt2[r]++;
    }

    vector<ll> temp;
    temp.reserve(cnt1.size() + cnt2.size());
    for (auto &x : cnt1) {
        temp.push_back(x.first);
    }
    for (auto &x : cnt2) {
        if (!cnt1.count(x.first)) {
            temp.push_back(x.first);
        }
    }

    set<ll> chk;
    int ok = 1;
    for (ll x : temp) {
        if (chk.count(x)) {
            continue;
            }
        ll cmp = (k - x) % k;
        chk.insert(x);
        chk.insert(cmp);

        if (x == cmp) {
            if (cnt1[x] != cnt2[x]) { 
                ok = 0; 
                break; 
            }
        } else {
            ll sum1 = cnt1[x] + cnt1[cmp];
            ll sum2 = cnt2[x] + cnt2[cmp];
            if (sum1 != sum2) { 
                ok = 0; 
                break; 
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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
 * 8 5 - 3 13
 * 4 5 - 1 9
 * 11 5 - 6 16
 * 
 * 8 5 - 3 13
 * 3 5 - 
 * 
 * mod k eq
 */