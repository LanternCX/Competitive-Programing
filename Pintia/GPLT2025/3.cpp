#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b == 0){
        if(!(a > 35 && c >= 33)){
            cout << "Shu Shi\n";
            cout << c << '\n';
            return;
        }
        cout << "Shi Nei\n";
        cout << a << '\n';
        return;
    }
    if(a > 35 && c >= 33){
        cout << "Bu Tie\n";
        cout << a << '\n';
    }else{
        cout << "Bu Re\n";
        cout << c << '\n';
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){     
        sol();
    }
}
