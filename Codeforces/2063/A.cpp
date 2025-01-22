#include <bits/stdc++.h>
using namespace std;
void sol(){
    int l, r;
    cin >> l >> r;
    if(l == r && r == 1){
        cout << 1 << '\n';
        return;
    }
    cout << r - l << '\n';
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