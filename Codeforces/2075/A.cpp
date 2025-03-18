#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    ll n, k;
    
    cin >> n >> k;
    ll ans = 0;
    if(n % 2 == 0){
        k -= k % 2;
        ans += n / k;
        if(n % k != 0){
            ans++;
        }
    }
    if(n % 2 == 1){
        if(k % 2 == 1){
            n -= k;
        }else{
            n -= k - 1;
        }
        ans++;
        k -= k % 2;
        ans += n / k;
        if(n % k != 0){
            ans++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}