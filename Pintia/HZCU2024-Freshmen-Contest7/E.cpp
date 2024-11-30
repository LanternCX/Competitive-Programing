#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if(n > 24){
        cout << 940313;
    }else{
        ll ans = 0;
        ll temp = 1;
        for(int i = 1; i <= n; i++){
            temp *= i;
            temp %= N;
            ans += temp;
            ans %= N;
        }
        cout << ans % N;
    }
    return 0;
}
/**
 * 1 2 6 
 */