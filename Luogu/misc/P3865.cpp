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
template <typename T>
struct ST {
    using fun = function<T(T &, T &)>;
    vector<vector<T>> st;
    fun op;
    ST(vector<T> arr, fun f = [](T a, T b){ return max(a, b); }) {
        op = f;
        int n = arr.size(), LOG = ceil(log2(n)) + 1;
        st = vector<vector<T>>(n, vector<T>(LOG));

        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }

        for (int j = 1; j < LOG; j++) {
            int t = (1 << (j - 1));
            for (int i = 0; i + t < n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int t = floor(log2(r - l + 1));
        debug(l, r);
        debug(l, (1 << t) - 1);
        debug(r - (1 << t) + 1, r - (1 << t) + 1 + (1 << t) - 1);
        return op(st[l][t], st[r - (1 << t) + 1][t]);
    }
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    ST<int> st(a);
    while(m--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(l, r) << '\n';
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