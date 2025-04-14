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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    swap(x, y);

    int ans = 0;
    for(int i = 0; i < n; i++){
        auto l = lower_bound(a.begin(), a.end(), sum - x - a[i]);
        auto r = lower_bound(a.begin(), a.end(), sum - y - a[i] + 1);
        ans += r - l;
        if (l - a.begin() <= i && i < r - a.begin()) {
            ans--;
        }
    }
    cout << ans / 2 << '\n';
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
 * sum - (a + b) > x
 * sum - (a + b) < y
 * 
 * sum - x - b > a
 * sum - y - b < a
 * 
 * b > x - a
 * b < y - a
 * 
 * 先确定 b 
 * 然后可以二分出 a
 * 
 */