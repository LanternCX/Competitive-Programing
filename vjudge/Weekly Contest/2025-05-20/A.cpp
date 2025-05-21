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
const ll N = 1e12;
vector<ll> mp; 
void sol(){
    ll n;
    cin >> n;
    int ans = INT_MAX;
    int m = mp.size();

    for (int i = 0; i < (1 << m); i++) {
        ll sum = 0;
        int cnt = 0;

        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                sum += mp[j];
                cnt++;
            }
        }

        if (sum > n) {
            continue;
        }

        int temp = __builtin_popcountll(n - sum);
        ans = min(ans, cnt + temp);
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
void init() {
    ll res = 1;
    for (int i = 1; res <= N; ++i) {
        mp.push_back(res);
        res *= i;
    }
    debug(mp);
} 
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    debug(mp);
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 由于 2^n 存在可以考虑直接拆位
 * 因此只需要考虑 阶乘数的贡献
 * 首先枚举阶乘数
 * 然后对阶乘数拆位考虑贡献
 */