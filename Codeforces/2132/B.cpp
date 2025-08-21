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
vector<ll> pow10;
void sol(){
    
}
int init() {
    pow10.push_back(1);
    for (int i = 1; i <= 18; i++) {
        pow10.push_back(pow10[i-1] * 10LL);
    }
}
int main(){
   int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> ans;
        __int128 pow10 = 1;
        for (int k = 1; k <= 18; ++k) {
            pow10 *= 10;
            __int128 temp128 = pow10 + 1;
            if (temp128 > (__int128)n) break;
            ll temp = (ll)temp128;
            if (n % temp == 0) {
                ans.push_back(n / temp);
            }
        }
        if (ans.empty()) {
            cout << 0 << '\n';
        } else {
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            cout << ans.size() << '\n';
            for (size_t i = 0; i < ans.size(); ++i) {
                if (i) cout << ' ';
                cout << ans[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
/**
 * 101010
 * 111111
 * 1111000011110000
 * 
 * 111000
 */