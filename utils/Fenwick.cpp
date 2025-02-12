#include <bits/stdc++.h>
using namespace std;
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
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}