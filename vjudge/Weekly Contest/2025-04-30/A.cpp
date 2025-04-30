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
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    if(a > b){
        swap(a, b);
    }
    // a min
    if(a < m){
        cout << "No\n";
        return;
    }
    a -= m;
    if(a + b < n){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
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
 * 第一类 吃多的 det--
 * 第二类 吃少的 det++
 * 
 * 先让第二类全吃掉 不能全吃就是 no
 * 再让第一类吃 可以把剩下的全部吃完 不能就是 no
 */