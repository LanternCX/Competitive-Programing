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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    ll sum = 0;
    for(auto &x : arr){
        cin >> x;
        sum += x;
    }
    if(sum / n == x && sum % n == 0){
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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