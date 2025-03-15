#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void solve(){
    ll n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    ll ans = LONG_LONG_MAX;
    ll sum = 0;
    if(k == 1){
        if(n % m == 0){
            cout << 0 << '\n';
            return;
        }
        cout << -1 << '\n';
        return;
    }

    for(int i = 0; ; i++, n /= k){
        if(n == 0){
            ans = min(ans, i * b);
            break;
        }
        sum = b * i;
        __int128 l = n, r = n;

        while((l / m) == (r / m) && l % m != 0){
            r = r * k + k - 1;
            l = l * k;
            sum += a;
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return ;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}