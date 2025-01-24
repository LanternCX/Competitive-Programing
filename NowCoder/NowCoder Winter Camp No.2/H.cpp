#include <bits/stdc++.h>
using namespace std;
void sol(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a < d - c) {
        cout << a << " " << c << "\n";
        cout << a << " " << c + 1 << "\n";
        cout << a + 1 << " " << d << "\n";
    } else {
        cout << a << " " << d << "\n";
        cout << a + 1 << " " << d << "\n";
        cout << b << " " << d - 1 << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}