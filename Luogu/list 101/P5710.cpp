#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    bool b1 = (x % 2 == 0);
    bool b2 = (x > 4) & (x <= 12);
    cout << ((b1 && b2) ? 1 : 0) << ' ';
    cout << ((b1 || b2) ? 1 : 0) << ' ';
    cout << ((b1 ^ b2) ? 1 : 0) << ' ';
    cout << (!(b1 || b2) ? 1 : 0);
    return 0;
}