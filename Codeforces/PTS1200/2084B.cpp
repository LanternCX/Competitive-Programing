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
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    sort(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());
    int g = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] % mn == 0){
            g = gcd(g, arr[i]);
        }
    }
    cout << (g == mn ? "Yes\n" : "No\n");
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
 * gcd(a, b, c) = gcd(gcd(a,b), c)
 * gcd[] = [3, 1]
 */