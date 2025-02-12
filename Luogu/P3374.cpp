#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> struct Fenwick{
    int n;
    vector<T> tr;

    Fenwick(int size): n(size), tr(size + 1){}
    
    int lowbit(int x){
        return x & -x;
    }

    void add(int idx, T val){
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
using BIT = Fenwick<ll>;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    BIT bit(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        bit.add(i + 1, arr[i]);
    }
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int x, k;
            cin >> x >> k;
            bit.add(x, k);
        }
        if(op == 2){
            int x, y;
            cin >> x >> y;
            cout << bit.query(x, y) << '\n';
        }
    }
    return 0;
}