#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n;
    cin >> n;
    if(n <= 0){
        cout << n << '\n';
        return;
    }
    for(int i = 0; i < 1e3; i++){
        if((1 << (i + 1)) == n){
            cout << (1 << (i + 1)) << '\n';
            return;
        }
        if((1 << i) <= n && (1 << (i + 1)) >= n){
            cout << (1 << i) << '\n';
            return ;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){     
        sol();
    }
}
