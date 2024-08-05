#include <bits/stdc++.h>
using namespace std;
int main(){
    double s;
    cin >> s;
    double a = 2;
    int ans = 0;
    while( s >= 0 ){
        s -= a;
        a *= 0.98;
        ans += 1;
    }
    cout << ans;
    return 0;
}