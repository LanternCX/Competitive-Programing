#include <bits/stdc++.h>
using namespace std;
void slove(){
    int x, y;
    cin >> x >> y;
    int a, b;
    if((y / x) * x != y){
        x = 0, y = 0;
        cout << x << ' ' << y  << '\n';
        return;
    }
    a = 1;
    b = y / x;
    cout << a << ' ' << b << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}