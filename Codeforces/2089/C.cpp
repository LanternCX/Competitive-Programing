#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    int x, y;
    cin >> x >> y;
    if(x == y){
        cout << -1 << '\n';
        return;
    }
    if((x & y) == 0){
        cout << 0 << '\n';
        return;
    }
    if (x < y) {
        swap(x, y);
    }
    ll k = (1LL << 31) - x;
    cout << k << '\n';
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
/**
 * (x + k) + (y + k) == (x + k) + (y + k) -  2 * (x + k) & (y + k)
 * 
 * 2 * (x + k) & (y + k) == 0
 * (x + k) & (y + k) == 0
 * 
 * 1 1 1 1 1 1 
 * 0 0 0 0 0 0
 * 
 * a ^ b = a + b - 2 * a & b
 * 
 */