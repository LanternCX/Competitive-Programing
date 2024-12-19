#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);
    int idx = k - 1;
    int i;
    for(i = 1; i <= n; i++){
        ans[idx] = i;
        idx += k;
        if(idx >= n) break;
    }

    for(int &x : ans){
        if(x == 0){
            x = ++i;
        }
    }
    for(int x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 1 2 3 4 5 6
 * 1 6 2 5 3 4
 * 
 * 3   1 4   2    
 * 4 6 2 8 3 1 5 7
 *     2 2 2 1 1 1
 * 3 6 1 4 7 2 5 8
 *     1 1 1 2 2 2
 * 3 4 1 5 6 2 7 8
 *     1 1 1 2 2 2
 */