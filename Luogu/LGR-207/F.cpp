#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> a;
    for(int i = 0; i < m; i++){
        int ans = 0;
        string op;
        cin >> op;
        if(op == "water"){
            int l, r;
            cin >> l >> r;
            for(int i = l; i <= r; i++){
                arr[i - 1]++;
            }
        }
        if(op == "rise"){
            int l, r, k;
            cin >> l >> r >> k;
            for(int i = l; i <= r; i++){
                if(arr[i - 1] >= k){
                    arr[i - 1] = 0;
                    ans++;
                }
            }
            a.push_back(ans);
        }
    }
    for(int x : a){
        cout << x << '\n';
    }
    return 0;
}