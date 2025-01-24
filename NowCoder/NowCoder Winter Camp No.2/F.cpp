#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll l, r;
    cin >> l >> r;
    cout << r - l + 1 << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    // for(int i = 0; i < 100; i++){
    //     for(int j = i; j < 100; j++){
    //         if(i + j == (i | j) + (i & j) + (i ^ j)){
    //             cout << i << ' ' << j << '\n';
    //         }
    //     }
    // }
    return 0;
}
/**
 * x xor y = x + y - 2 * x and y
 * 0 = x and y + x or y - 2 * x and y
 * x and y == x or y
 * 
 * and: 
 * 1 1 1
 * 1 0 0
 * 0 1 0
 * 0 0 0
 * 
 * or:
 * 1 1 1
 * 1 0 1 
 * 0 1 1
 * 0 0 0
 * 
 */