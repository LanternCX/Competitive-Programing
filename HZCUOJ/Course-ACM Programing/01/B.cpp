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
    string s;
    while (cin>>s) {
        int ans = 0;
        int lens = s.size();
        for (int i = 0; i < lens; i++) {
            ans += s[i] - '0';
        }
        if (ans == 0)break;
        else
            cout << (ans- 1) % 9 + 1 << endl;
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