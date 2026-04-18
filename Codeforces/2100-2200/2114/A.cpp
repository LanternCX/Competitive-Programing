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
    cin >> s;
    int n = stoi(s);
    int r = int(floor(sqrt(n) + 0.5));
    if(r * r != n) {
        cout << -1 << "\n";
    } else {
        cout << 0 << " " << r << "\n";
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