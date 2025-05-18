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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    auto work = [&](ll l){
        ll cnt = 0;
        ll t = l;
        while (t > 1) {
            t >>= 1;
            cnt++;
        }
        return ((1LL << cnt) == l ? cnt : cnt + 1);
    };
    ll ans1 = 1 + work(min(a, n - a + 1)) + work(m);
    ll ans2 = 1 + work(min(b, m - b + 1)) + work(n);

    cout << min(ans1, ans2) << "\n";
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * M 尽量多切 F 尽量少切
 * a, b
 * a > b 按照 b 切， 反之
 * 所以 swap
 * 不对
 * 好像直接贪心模拟？
 * 
 * 
 */