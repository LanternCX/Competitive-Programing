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
    while(cin >> n){
        if(n == 0){
            return;
        }
        vector<int> a(n);
        for(auto &x : a){
            cin >> x;
        }
        sort(a.begin(), a.end(), [](int a, int b){
            return abs(a) > abs(b);
        });
        for(auto x : a){
            cout << x << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}