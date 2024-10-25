#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void slove(){
    ll n;
    cin >> n;
    if(n <= 2){
        cout << 1 << '\n';
    }else {
        ll ans = 1;
        while(ans < n){
            ans *= 2;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        slove();
    }
    return 0;
}