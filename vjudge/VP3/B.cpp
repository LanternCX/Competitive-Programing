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
    ll n;
    cin >> n;
    n /= 1000;
    n %= 24 * 60 * 60;
    int s = n % 60;
    n /= 60;
    int m = n % 60;
    n /= 60;
    int h = n % 24;
    printf("%02d:%02d:%02d", h, m, s);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 24 * 60 * 60
 * 60min
 * 60 * 60
 */