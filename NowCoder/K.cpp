#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    ll temp = max(x * a, y * b);
    cout << (max(temp, z * c)) << '\n';
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