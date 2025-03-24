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
struct node{
    ll x, y;
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<node> a(n), b(m);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x + y, x - y};
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        b[i] = {x + y, x - y}; 
    }
    ll mnx = LLONG_MAX, mny = LLONG_MAX;
    ll mxx = LLONG_MIN, mxy = LLONG_MIN;
    for(int i = 0; i < n; i++){
        mnx = min(a[i].x, mnx);
        mny = min(a[i].y, mny);
        mxx = max(a[i].x, mxx);
        mxy = max(a[i].y, mxy);
    }
    ll ans = LLONG_MAX;
    for(auto [x, y] : b){
        ll dist = 0;
        dist = max({
            abs(x - mnx),
            abs(x - mxx),
            abs(y - mny),
            abs(y - mxy)
        });
        debug(dist);
        ans = min(dist, ans);
    }
    cout << ans << '\n';
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
 * 对于一个点 (x, y)
 * 到点 (a, b) 的曼哈顿距离为
 * abs(a - x) + abs(b - y)
 * 
 * A(x1, y1) B(x2, y2)
 * D(A, B) = abs(x1 - x2) + abs(y1 - y2)
 * 
 * A'(x1 + y1, x1 - y1) B'(x2 + y2, x2 - y2)
 * D(A, B) = d(A', B')
 * = max(abs(x1 + y1 - (x2 + y2)), abs(x1 - y1 - (x2 - y2)))
 * 
 * 1） x > a
 * 
 * 1 0 0 0 0 
 * 0 1 0 0 0 
 * 0 0 2 0 0 
 * 0 2 0 0 0 
 * 0 0 0 0 0 
 * 0 0 0 0 0 
 * 
 * 
 */