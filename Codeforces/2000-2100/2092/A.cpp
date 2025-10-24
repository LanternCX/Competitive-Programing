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
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    sort(arr.begin(), arr.end());
    cout << arr[n - 1] - arr[0] << '\n';
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
 * 挑出两个数
 * 这两个数各加上一个数
 * 使得他们的 gcd 最大
 */