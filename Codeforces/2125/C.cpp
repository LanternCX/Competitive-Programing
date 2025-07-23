#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;

vector<ll> mp;

void init() {
    vector<ll> temp = {2,3,5,7};
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4;j++) {
            mp.push_back(temp[i] * temp[j]);
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 4; k++) {
                 mp.push_back(temp[i] * temp[j] * temp[k]);
            }
        } 
    }
    mp.push_back(2 * 3 * 5 * 7);
}

void sol() {
    ll l, r;
    cin >> l >> r;
    auto count = [](ll N) -> ll {
         if (N <= 0) return 0;
        vector<ll> P = {2, 3, 5, 7};
        ll c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for (int i = 0; i < 4; ++i) {
            c1 += N / P[i];
        }
        for (int i = 0; i < 6; ++i) {
            c2 += N / mp[i];
        }
        for (int i = 6; i < 10; ++i) {
            c3 += N / mp[i];
        }
        c4 = N / mp[10];
        return N - (c1 - c2 + c3 - c4);
    };
    cout << (count(r) - count(l - 1)) << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--){
        sol();
    }
    return 0;
}
