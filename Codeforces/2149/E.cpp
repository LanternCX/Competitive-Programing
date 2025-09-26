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
#define int ll
void sol(){
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    
    auto work = [&](vector<int> &a, int k, int lim) {
        map<int, int> cnt;
        int R = 0;
        int L = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(cnt[a[i]] + 1 == 1) {
                R++;
            }
            cnt[a[i]]++;

            while(R > k) {
                if(cnt[a[L]] - 1 == 0) {
                    R--;
                }
                cnt[a[L]]--;
                L++;
            }
            // i - L + 1
            debug(L, R);
            int len = i - L + 1;
            
            if(len > lim) {
                res += lim;
            } else {
                res += len;
            }
        }
        return res;
    };
    int ans = work(a, k, r) - work(a, k, l - 1) - work(a, k - 1, r) + work(a, k - 1, l - 1);
    cout << ans << "\n";
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
/**
 * 差分？
 * dp?
 * 滑动窗口？
 * 
 * 11112345
 * 10001234
 * 
 * 滑窗
 * 可以算 len <= lim && cnt <= k 的子数组的个数
 * 
 * 然后只要对 lim 和 k 左右的区间减去就好了
 */