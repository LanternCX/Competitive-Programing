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
    int tag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!tag) {
            cout << -1 << ' ';
        } else {
            cout << 3 << ' ';
        }
        tag = !tag;
    }
    if (n % 2) {
        cout << -1 << '\n';
    } else {
        cout << 2 << '\n';
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
 * -1 2
 * -1 3 -1 2
 * 
 * -1 3 -1 3 -1
 * -1 3 -1 3 -1
 * 
 */