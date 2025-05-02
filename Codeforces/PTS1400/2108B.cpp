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
#define int long long
void sol(){
    int n, x;
    cin >> n >> x;
    if(n == 1 && x == 0){
        cout << -1 << '\n';
        return;
    }
    if(x == 0){
        if(n % 2 == 0){
            cout << n << '\n';
        }else {
            cout << n - 1 + 4 << '\n';
        }
        return;
    }

    vector<int> bin;
    while(x != 0){
        bin.push_back(x & 1);
        x >>= 1;
    }

    ll ans = 0;
    int cnt = n, k = 0;
    int len = bin.size();
    for(int i = 0; i < len; i++){
        ans += (1 << i) * bin[i];
        cnt -= bin[i];
        k += bin[i];
    }

    if(cnt <= 0){
        cout << ans << '\n';
        return;
    }

    if(cnt % 2 == 0){
        cout << ans + cnt << '\n';
    }else{
        ans += cnt - 1;
        // 只有一个 1 并且在一号位贡献就是 4
        if(k > bin[0]){
            cout << ans + 2 << '\n';
        }else{
            cout << ans + 4 << '\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        debug(t);
        sol();
    }
    return 0;
}
/**
 * 首先拆位
 * 
 * 如果 1 的位有 k 个
 * 就先构造 k 个数
 * 
 * 然后 cnt = n - k
 * 还需要 cnt 个数
 * 
 * 如果还需要偶数个
 * 那就直接补偶数个 1
 * 
 * 对于
 * 00 -> 01 01 贡献为 2
 * 对于
 * 01 -> 11 10 贡献为 4
 * 
 * 只需要检查最后一位
 * 如果是 0 那么之前一定构造过一个 1..00 贡献为 2
 * 如果是 1 那么之前一定构造过一个 0..01 贡献为 4
 * 
 * 如果 cnt > 2 一定构造过一个 01
 * 所以只有一个 1 并且在 1 号位贡献就是 4 不然一定是 2
 */