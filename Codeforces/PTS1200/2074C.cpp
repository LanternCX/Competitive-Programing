#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
map<int, int> mp;
void init(){
    for(int i = 0; (1 << i) < 1e9; i++){
        mp[1 << i]++;
    }
}
void sol(){
    int x;
    cin >> x;
    int ans = -1;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 30; j++){
            ll y = (1LL << i) | (1LL << j);
            ll z = x ^ y;
            if(y < x && x + y > z && y + z > x){
                ans = y;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--){
        sol();
    }
    return 0;
}
/**
 * x, y, x ^ y
 * 
 * x + y > x ^ y
 * x + x ^ y > y
 * y + x ^ y > x
 * 
 * 
 * x ^ y == x + y - 2 * x & y
 * 
 * x + y > x + y - 2 * x & y ==> x & y > 0
 * x + x - 2 * x & y > 0 ==> x > x & y
 * y + x ^ y > x ==> y > x & y
 * 
 * x & y > 0
 * x > x & y
 * y > x & y
 * 
 * 1 0 0 0 0 1 
 * 1 0 0 0 0 1
 * and
 * 0 0 0 0 0 1
 * 
 */