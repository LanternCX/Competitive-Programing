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
    if(n % 2 == 0){
        cout << -1 << '\n';
        return;
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << ' ';
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << ' ';
    }
    cout << '\n';
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
 * 1 2 3 4 5 
 * 1 0 0 0 0
 * 0 1 3 0 0
 * 0 0 1 3 5
 * 5 2 0 1 3
 * 3 5 2 4 1
 * 1 3 5 2 4
 * 
 * 1 2 3 4
 * 1 3 4 2
 * 2 1 3 4
 * 
 * 1 2 3
 * 1 3 2
 */