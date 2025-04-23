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
int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
float divide(int a, int b) {
    float temp = 1.0 * a / b;
    float res = 1.0 * round((temp * 100)) / 100;
    return res;
}
void sol(){
    char op;
    cin >> op;
    if(op == '+'){
        ll a, b;
        cin >> a >> b;
        cout << a + b;
    }
    if(op == '-'){
        ll a, b;
        cin >> a >> b;
        cout << a - b;
    }
    if(op == '*'){
        ll a, b;
        cin >> a >> b;
        cout << a * b;
    }
    if(op == '/'){
        ll a, b;
        cin >> a >> b;
        if ((a / b) == 1.0 * a / b) {
            cout << a / b;
        } else {
            cout << fixed << setprecision(2) << divide(a, b);
        }
    }
    cout << '\n';
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