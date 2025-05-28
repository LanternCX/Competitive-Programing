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
    unordered_set<string> st;
    st.reserve(n * 2);

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        st.insert(a + "#" + b);
        st.insert(b + "#" + a);
    }

    int m;
    cin >> m;
    while (m--) {
        string x, y;
        cin >> x >> y;
        string key = x + "#" + y;
        if (st.count(key)) {
            cout << "(~_~)\n";
        } else {
            cout << "o(@O@)o\n";
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