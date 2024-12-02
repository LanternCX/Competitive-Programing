#include <bits/stdc++.h>
using namespace std;
void sol(){
    int x, y;
    cin >> x >> y;
    if(x <= y){
        cout << y - x << '\n';
    }else {
        int det = y - x;
        int num;
        int sum = 0;
        for(int i = 0; i < 30; i++){
            sum += i << i;
            if((1 << i) > det){
                
            }
        }
    }
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
/**
 * To Be Done
 * 
 * 13: 1101
 * 10: 1010
 * 
 */