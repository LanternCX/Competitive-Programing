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

ll inf = 1e18;
void sol() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (auto &x : b) {
        cin >> x;
    }

    vector<ll> maxv = {0, -inf};
    vector<ll> minv = {0,  inf};

    for (int i = 0; i < n; i++) {
        ll nmax[2] = {-inf, -inf};
        ll nmin[2] = { inf,  inf};

        for (int p = 0; p < 2; p++) {
            if (maxv[p] > -inf) {
                nmax[p] = max(nmax[p], maxv[p] - a[i]);
                nmin[p] = min(nmin[p], minv[p] - a[i]);
            }
            if (maxv[1 - p] > -inf) {
                nmax[p] = max(nmax[p], b[i] - minv[1-p]);
                nmin[p] = min(nmin[p], b[i] - maxv[1-p]);
            }
        }
        
        maxv[0] = nmax[0];  
        maxv[1] = nmax[1];

        minv[0] = nmin[0]; 
        minv[1] = nmin[1];
    }
    cout << max(maxv[0], maxv[1]) << "\n";
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * dp?
 * 
 * dp[i] 表示前 i 个的最大值
 * 
 * 好像不对
 * 
 * 首先蓝色会取反
 * 也就是蓝色使用的奇偶次
 * 红色不改变符号
 * 
 * 答案就是 sum(blue - red) * even?
 * 
 * 也就是说我们只要对使用奇数次蓝色和偶数次蓝色分别进行判断？
 * emm
 * 
 */