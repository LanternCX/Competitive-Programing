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
    double w;
    cin >> n >> w;
    vector<double> a(2 * n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    double g = a[0];
    double b = a[n];

    double l = 0.0, r = min(g, b / 2.0);
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (3.0 * n * mid <= w){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << 3.0 * n * l << "\n";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(9);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}