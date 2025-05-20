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
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 520) {
            cout << i + 1 << '\n';
            return;
        }
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