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
    cin >> n;
    vector<ll> xs(n), ys(n);
    for(int i = 0; i < n; i++){
        cin >> xs[i] >> ys[i];
    }
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    ll x1 = LLONG_MAX, x2 = LLONG_MAX;
    ll xn = LLONG_MIN, xnm1 = LLONG_MIN;
    for(ll x : xs){
        if (x < x1) {
            x2 = x1; x1 = x; 
        } else if (x > x1 && x < x2) {
            x2 = x;
        }
        if (x > xn) { 
            xnm1 = xn; xn = x; 
        } else if (x < xn && x > xnm1) {
            xnm1 = x;
        }
    }
    int cnt_x1 = 0, cnt_xn = 0;
    for(ll x : xs){
        if (x == x1) {
            cnt_x1++;
        }
        if (x == xn) {
            cnt_xn++;
        } 
    }
    ll y1 = LLONG_MAX, y2 = LLONG_MAX;
    ll yn = LLONG_MIN, ynm1 = LLONG_MIN;
    for(ll y : ys){
        if(y < y1) {
                y2 = y1; 
                y1 = y;
        } else if(y > y1 && y < y2) {
            y2 = y;
        }

        if(y > yn) {
            ynm1 = yn; 
            yn = y; 
        } else if (y < yn && y > ynm1) {
            ynm1 = y;
        }
    }
    int cnt_y1 = 0, cnt_yn = 0;
    for(ll y : ys){
        if(y == y1) {
            cnt_y1++;
        }
        if(y == yn) {
            cnt_yn++;
        }
    }
    ll dx0 = xn - x1 + 1;
    ll dy0 = yn - y1 + 1;
    ll ans = dx0 * dy0;

    for(int i = 0; i < n; i++){
        ll xmin = x1, xmax = xn;
        ll ymin = y1, ymax = yn;
        if(xs[i] == x1 && cnt_x1 == 1) xmin = x2;
        if(xs[i] == xn && cnt_xn == 1) xmax = xnm1;
        if(ys[i] == y1 && cnt_y1 == 1) ymin = y2;
        if(ys[i] == yn && cnt_yn == 1) ymax = ynm1;

        ll dx = xmax - xmin + 1;
        ll dy = ymax - ymin + 1;
        ll s_temp = dx * dy;
        ll c;
        if(s_temp > n - 1) {
            c = s_temp;
        } else {
            ll c1 = (dx + 1) * dy;
            ll c2 = dx * (dy + 1);
            c = min(c1, c2);
        }
        ans = min(ans, c);
    }

    cout << ans << "\n";
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
 * 首先可以很简单的算出不移动的情况下的代价
 * 是移动不是去掉
 * emm
 * 最小是 n 
 * 然后正常模拟就好
 * 应该吧
 */