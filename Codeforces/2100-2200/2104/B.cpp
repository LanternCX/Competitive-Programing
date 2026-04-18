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
#define int long long
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
        return op(st[l][t], st[r - (1 << t) + 1][t]);
    }
};
void sol(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ST<int> st(a);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        cout << pre[n] - pre[n - i + 1] + st.query(0, n - i + 1) << ' ';
    }
    cout << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}