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
        }else{
            cout << n + 3 << '\n';
        }
        return;
    }

    vector<int> bin;
    int temp = x;
    while (temp != 0) {
        bin.push_back(temp & 1);
        temp >>= 1;
    }

    ll ans = 0;
    int cnt = n;
    int len = bin.size();
    for(int i = 0; i < len; i++){
        ans += (1 << i) * bin[i];
        cnt -= bin[i];
    }

    if(cnt <= 0){
        cout << ans << '\n';
        return;
    }

    // 偶数个就可以直接全部补 1 
    if(cnt % 2 == 0){
        cout << ans + cnt << '\n';
    }
    
    // 奇数个需要构造
    if(cnt % 2 == 1){
        // 留下最后一个
        ans += cnt - 1;

        if(n - cnt > bin[0]){
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
        sol();
    }
    return 0;
}
/**
 * 拆位
 * 
 * 补 1 
 * 分奇偶
 */