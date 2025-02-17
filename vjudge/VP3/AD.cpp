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
    ull n;
    cin >> n;
    ull cnt = 0;
    vector<ll> a;
    for(ull i = 1; i * i <= n; i++){
        if(n % i == 0){
            a.push_back(i);
            if(i * i != n){
                a.push_back(n / i);
            }
        }
    }
    for (auto x: a) {
        for (auto y: a) {
            if (n % (x * y) == 0) {
                cnt++;
            }
        }
    }
    cout << cnt;
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * c(n, m) = n! / (n - m)! * m!
 */