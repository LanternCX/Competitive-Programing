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
#define int long long
void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    int res = c >= a && c >= b;
    int avg = (a + b + c) / 3;
    debug(avg);
    debug(abs((avg - a)) + abs(avg - b));
    debug(abs(c - avg));
    res =  c >= a && c >= b && (a + b + c) % 3 == 0 && abs((avg - a)) + abs(avg - b) == abs(c - avg) && b <= avg && a <= avg && c >= avg;
    cout << (res ? "YES\n" : "NO\n");
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}