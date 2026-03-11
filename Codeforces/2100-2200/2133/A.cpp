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
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }
    set<int> st;
    for (auto x : arr) {
        if(st.count(x) > 0) {
            cout << "YES\n";
            return;
        } else {
            st.insert(x);
        }
    }
    cout << "NO\n";
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