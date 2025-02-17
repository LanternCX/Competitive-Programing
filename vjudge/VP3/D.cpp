#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<ull, ull>;
vector<ull> arr = {0};
void sol(){
    ull l, r;
    cin >> l >> r;
    auto calc = [&](ull x){
        if(x == 0){
            return 0ULL;
        }
        ull n = ceil((sqrtl(1 + 8 * x)  - 1) / 2);
        debug(x, n);
        return n;
    };
    auto work = [&](ull x){
        ull n = calc(x);
        ull t = x - n * (n - 1) / 2;
        ull k = (n - 1) * n * (n + 1) / 6;
        return k + (t + 1) * t / 2;
    };
    cout << work(r) - work(l - 1) << '\n';
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
 * 1 1 2 1 2 3 1 2 3 4
 * 1 2 3 4
 * 1 + 2 + 3 + 4 + ... + n = (1 + n) * n / 2 = x
 * 1 + 1 + 2 + 1 + 2 + 3
 * 1 + 3 + 6
 * 也就是说和可以在 sqrt 内算出来 1e6
 * 也就是说我们其实只要算出第 n 项是多少就好了
 * 
 * n 第 n 条子数列
 * (1 + n) * n / 2 = x
 * n = ceil((sqrtl(1 + 8 * x)  - 1) / 2)
 * 
 */