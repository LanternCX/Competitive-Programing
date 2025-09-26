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
    int h, d;
    cin >> h >> d;
    int l = 0, r = d;
    auto check = [&](int x) -> bool {
        int tot = h + x;
        int need = d * (d + 1) / 2;
        if(tot < need) {
            return 0;
        }
        int m = (sqrt(8.0 * tot + 1) - 1) / 2;
        return m >= d;
    };
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << d + l << "\n"; 
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
 * 贪心？
 * 等差数列求和
 * n(n - 1) / 2
 * 
 * 二分休息的次数 x
 * 总体力是 h + x
 * 
 */