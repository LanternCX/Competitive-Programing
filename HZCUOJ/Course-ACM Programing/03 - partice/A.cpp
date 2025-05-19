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
struct node {
    int x, y;
};
void sol(){
    int n;
    auto work = [&](node a, node b, node c) {
        double x1 = a.x - b.x;
        double y1 = a.y - b.y;
        
        double x2 = a.x - c.x;
        double y2 = a.y - c.y;
        
        return (x1 * y2 - x2 * y1) / 2;
    };
    while (cin >> n) {
        if(n == 0){
            return;
        }
        double ans = 0;
        vector<node> arr(n);
        for (auto &nd : arr) {
            cin >> nd.x >> nd.y;
        }
        for (int i = 1; i < n - 1; i++) {
            ans += work(arr[0], arr[i], arr[i + 1]);
        }
        cout << ans << '\n';
    }  
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(1);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}