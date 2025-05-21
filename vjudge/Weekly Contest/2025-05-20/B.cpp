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
struct node {
    int idx, v;
};
template<typename T> struct Fenwick{
    int n;
    vector<T> tr;

    Fenwick(int size) : n(size), tr(size + 1){}

    int lowbit(int x){
        return x & -x;
    }

    void update(int idx, T val){
        for(int i = idx; i <= n; i += lowbit(i)){
            tr[i] += val;
        }
    }

    T query(int idx){
        T res = T();
        for(int i = idx; i > 0; i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
using BIT = Fenwick<int>;
void sol(){
    int n, m;
    cin >> n >> m;
    ll siz = n * m;
    vector<int> a(siz);
    for (auto &x : a) {
        cin >> x;
    }
    // idx, a[i]
    vector<node> arr;
    for (int i = 0; i < siz; i++) {
        arr.push_back({i, a[i]});
    }
    sort(arr.begin(), arr.end(), [&](node a, node b){
        if (a.v != b.v) {
            return a.v < b.v;
        }
        return a.idx > b.idx;
    });

    vector<int> pos(siz);
    for (int i = 0; i < siz; i++) {
        pos[arr[i].idx] = i + 1;
    }

    BIT bit(siz + 1);
    ll ans = 0;
    for (int i = 0; i < siz; i++) {
        int p = pos[i];
        if (p > 0) {
            ans += bit.query(p - 1);
        }
        bit.update(p, 1);
    }

    cout << ans << "\n";
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
/**
 * 只需要对视力相等的人讨论
 * 可以通过数据结构维护
 * 
 * 然后模拟
 * 
 * 其实只需要排序就行了
 * 
 * 对于视力相等的人 按照下标从大到小排序
 * 
 * 每行的贡献就是求前缀和
 * 直接树状数组暴力
 */