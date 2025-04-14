#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define  int ll

struct BIT{
    int n;
    vector<int> tr;
    BIT(int siz){
        n = siz;
        tr = vector<int>(siz + 1);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void add(int idx, int x){
        for(int i = idx; i <= n; i += lowbit(i)){
            tr[i] += x;
        }
    }

    int query(int idx){
        int res = 0;
        for(int i = idx; i >= 1; i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }

    int query(int l, int r){
        return query(r) - query(l - 1);
    }
};

void sol(){
    int n, m;
    cin >> n >> m;
    BIT bit(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        bit.add(i, x);
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

}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}