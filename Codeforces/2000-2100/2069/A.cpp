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
    n -= 2;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    debug(arr);
    if(n >= 3){
        for(int i = 1; i < n - 1; i++){
            if(arr[i] == 0 && arr[i - 1] == 1 && arr[i + 1] == 1){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
 * 1 1 1 0 1 0 0 0
 * 0 1 0 0 0 0 1 1
 * 
 *   0 1 1 1
 * 0 1 0 1 1 0 0 1
 * 
 * 0 1 1 1
 *   0 1
 * 
 * 01110
 * 00100
 */