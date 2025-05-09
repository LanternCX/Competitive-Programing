#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int p = 1e9 + 7;
const int inv = 5e8 + 4;

void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x = (x + a[i]) % p;
        y = (y + a[i] * a[i] % p) % p;
    }
    
    int ans = (x * x % p - y + p) % p;
    ans = ans * inv % p;

    int cnt = 1;
    for(int i = n; i >= 2; i--){
        int a = (((i - 1) % p) * (i % p)) % p * inv % p;
        cnt = cnt * a % p;
    }
    
    cout << ans << ' ' << cnt << '\n';
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
