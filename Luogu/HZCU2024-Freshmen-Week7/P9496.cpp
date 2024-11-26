#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll n, m;
    cin >> n >> m;
    int idx = 0;

    ll ans = 0;
    bool tag1 = 0;
    bool tag2 = 0;
    while(n > 0 || m > 0){
        int a = n % 2;
        int b = m % 2;
        // cout << a << ' ' << b << '\n';
        if(a == 1 && b == 0 && !tag1){
            tag1 = 1;
            ans++;        
        }
        if(a == 0 && b == 1 && !tag2){
            tag2 = 1;
            ans++;
        }
        n /= 2;
        m /= 2;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        sol();
    }
    return 0;
}
/**
 * 0001
 * 0100
 */