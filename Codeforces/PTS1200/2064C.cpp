#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    ll ans = 0;
    vector<ll> pre(n);
    pre[0] = max(0, arr[0]);
    for(int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + max(0, arr[i]);
    }
    vector<ll> suf(n);
    suf[n - 1] = abs(min(0, arr[n - 1]));
    for(int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1] + abs(min(0, arr[i])); 
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, pre[i] + suf[i]);
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
 * 序列 a 
 * 选择 a[i]
 * ans = sum of a[i]
 * choose a[i]
 * a = a[0] ~ a[i]
 * 
 * 那么要如何选择？
 * 选左端的第一个大于 0 和右端的第一个 小于 0
 * 
 * 实际上 存在一个跳变点
 * 可以去枚举这个跳变点
 * 算出最大的答案
 * 
 * 1 1 1 1 -1 1 -1 -1 -1 -1
 */