#include <bits/stdc++.h>
using namespace std;
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
int main(){
    cout << floor(log2(9));
    return 0;
}