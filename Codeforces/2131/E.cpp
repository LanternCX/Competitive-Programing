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
    vector<ull> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    
    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";
         return;
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == b[i]) {
            continue;
        }
        if((a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i]){
            cout << "NO" << '\n';
            return;
        }
    }
 
    cout << "YES" << '\n';
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