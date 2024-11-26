#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;
    cin >> k;
    int mx = 0;
    for(int i = 0; i < 100; i++){
        if(k <= 1 << i){
            mx = i;
            cout << (1 << i) << ' ';
            break;
        }
    }
    for(int i = mx; i >= 0; i--){
        k %= 1 << i;
        if(k <= 0){
            cout << mx - i;
            break;
        }
    }
    return 0;
}
/**
 * 8 
 * 4  4
 * 4 2 2  4 + 2 = 6
 * 
 * 5 = 4 + 1
 * 
 */