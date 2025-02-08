#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol(){
    ll x;
    char op;
    cin >> x >> op;
    if(op == '*'){
        cout << x << ' ' << 1;
    }
    if(op == '+'){
        cout << x - 1 << ' ' << 1;
    }
    if(op == '-'){
        cout << x + 1 << ' ' << 1;
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
    return 0;
}