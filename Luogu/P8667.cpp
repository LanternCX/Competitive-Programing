#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());    
    sort(c.begin(), c.end());

    ll ans = 0;
    for(int x : b){
        auto it1 = lower_bound(a.begin(), a.end(), x);
        ll cnt1 = it1 - a.begin();
        auto it2 = upper_bound(c.begin(), c.end(), x);
        ll cnt2 = c.end() - it2;
        ans += cnt1 * cnt2;
    }
    cout << ans;
    return 0;
}