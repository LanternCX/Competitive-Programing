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
    int d, r, x, y;
    cin >> d >> r >> x >> y;
    x = abs(x);
    y = abs(y);
    debug(x, y);
    if(y > d){
        y = y - d;
        double ans = r - sqrtl(x * x + y * y);
        printf("%.0lf", abs(ans));
    }else{
        double ans = x - r;
        printf("%.0lf", abs(ans));
    }
    printf("\n");
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