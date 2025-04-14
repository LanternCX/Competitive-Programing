#include <bits/stdc++.h>
#define int long long
using namespace std;
int p;
int binpow(int x, int n){
    if(n == 0){
        return 1; 
    }
    if(n % 2 == 0){
        int res = binpow(x, n / 2) % p;
        return (res * res) % p;
    }
    if(n % 2 == 1){
        int res = binpow(x, n - 1) % p;
        return ((res % p) * (x % p)) % p;
    }
    return -1;
}
void sol(){
    int a, b;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld", a, b, p, binpow(a, b) % p);
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}