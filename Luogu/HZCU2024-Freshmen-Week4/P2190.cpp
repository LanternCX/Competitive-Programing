#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(x < y){
            a[x] += z;
            a[y] -= z;
        }else {
            a[x] += z;
            a[n] -= z;
            a[1] += z;
            a[y] -= z;
        }
    }
    ll mx = -1e7;
    for(int i = 1; i <= n; i++){
        a[i] = a[i - 1] + a[i];
        mx = max(mx, a[i]);
    }
    int ans = mx % 36 == 0 ? mx / 36 : mx / 36 + 1;
    cout << ans;
    return 0;
}
/**
 * 
 */