#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1000000001;
ll isP(int n){
    for(int i = 2; i < n; i++){
        if(n % 2 == 0){
            return 0;
        }
    }
    return 1;
}
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = p;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            ans = -1;
        }
    }
    cout << ans << '\n';
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
 * (lc + 1) % lc != 0
 * 10^9 * 10^9 = 10^18 *
 */