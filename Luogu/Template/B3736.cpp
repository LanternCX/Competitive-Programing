#include <bits/stdc++.h>
using namespace std;
// gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
void sol(){
    int x, y, z;
    cin >> x >> y >> z;
    cout << gcd(x, gcd(y, z));
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}