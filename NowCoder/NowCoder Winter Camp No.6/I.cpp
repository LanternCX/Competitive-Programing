#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
struct Fenwick{
    int n;
    vector<T> tr;
 
    Fenwick(int n) : n(n), tr(n + 1, 0){}

    int lowbit(int x){
        return x & -x;
    }

    void update(int x, T c){
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    T query(int x){
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
using BIT = Fenwick<int>;
struct node{
    int l, r, id;
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), pos(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        // arr[i] 的位置，由于是排列所以只需要存一个
        pos[arr[i]] = i;
    }

    vector<vector<node>> query(n + 1);
    for(int i = 0; i < m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        // arr[x] 的查询
        query[arr[x]].push_back({l, r, i});
    }

    vector<int> ans(m);
    BIT bit(n);
    // 从小到大更新，此时树状数组中只有 <= i 的数的位置被更新，也就是说此时求得的区间和就是 <= i 的数的个数
    for(int i = 1; i <= n; i++){
        bit.update(pos[i], 1);
        for(auto nd : query[i]){
            int l = nd.l, r = nd.r, id = nd.id;
            int cnt = bit.query(l, r);
            int idx  = l + cnt - 1;
            ans[id] = idx;
        }
    }
    for(auto x : ans){
        cout << x << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
}