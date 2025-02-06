#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    int res = 0, cnt = 0;
    while (l < r){
        int mid = (l + r) / 2;
        int tot = 0;
        for (int lx = 1; lx <= n; lx = n / (n / lx) + 1){
            int rx = n / (n / lx);
            int a = n - n / lx * lx;
            int k = (n / lx);
            if (a < mid){
                continue;
            }
            tot += min((a - mid) / k + 1, rx - lx + 1);
        }
        if (tot >= k){
            l = mid + 1;
        } else{
            r = mid - 1;
            cnt = tot;
            res = mid;
        }
    }
    ll ans = 1LL * (k - cnt) * (res - 1);
    for (int lx = 1; lx <= n; lx = n / (n / lx) + 1){
        int rx = n / (n / lx);
        int a = n - n / lx * lx;
        int k = (n / lx);
        if (a < res){
            continue;
        }
        int len = min((a - res) / k + 1, rx - lx + 1);
        ans += 1LL * (a * 2 - k * (len - 1)) * len / 2;
    }
    cout << ans;
    return 0;
}

/**
 * [i, j] -> n / i == n / j
 * -> [i, n / (n / i)], maxj = n / (n / i)
 * 
 * x % i = n - (n / i) * i
 *
 * for i to n / (n / i) :
 *  k = n / i
 *  x % i = n - (n / i) * i = n - k * i
 *  diff: d = k = n / i, a[0] = x / i[0]
 * 
 *  sum = (a[0] + a[n]) * n / 2
 * 
 * 
 * 
 */