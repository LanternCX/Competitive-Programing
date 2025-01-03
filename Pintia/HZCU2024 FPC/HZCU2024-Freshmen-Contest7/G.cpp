#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll x, y;
    cin >> x >> y;
    if(x <= y){
        cout << y - x << '\n';
        return;    
    }else{
        ll cost = 0;
        for(int i = 30; i >= 0; i--){
            int a = (x >> i) & 1;
            int b = (y >> i) & 1;
            if(a == 1 && b == 0){
                cost += (1 << i);
                x -= (1 << i);
                if(x <= y){
                    break;
                }
            }
        }
        cout << cost + y - x << '\n';
    }

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
 * 1110 14 1010 10
 * 1011 11
 * 
 * 
 * 1 + 2 + 
 * 
 * &
 * 1 1 1 
 * 1 0 0
 * 0 1 0
 * 0 0 0
 * 
 */