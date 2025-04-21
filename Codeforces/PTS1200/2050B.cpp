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
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll a = 0, b = 0;
    for(int i = 1; i < n; i += 2){
        a += arr[i];
    }
    for(int i = 0; i < n; i += 2){
        b += arr[i];
    }
    int x = n / 2, y = (n + 1) / 2;
    debug(a, b, x, y);
    cout << ((a / x == b / y && a % x == 0 && b % y == 0) ? "YES\n" : "NO\n");  
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