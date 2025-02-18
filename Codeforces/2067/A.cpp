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
    int a, b;
    cin >> a >> b;
    if(a < b && b - a == 1){
        cout << "Yes\n";
    }else if (a > b &&((a - b + 1) % 9 == 0)) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
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
/**
 * 100 101
 * 
 * 199 19
 * 
 * 200 2
 * 
 * 20
 * 99 1
 * 999 1000
 * 
 */