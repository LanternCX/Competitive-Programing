#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += pre[i - 1] * a[i];
    }
    cout << ans;
    return 0;
}