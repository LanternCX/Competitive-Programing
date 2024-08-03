#include <bits/stdc++.h>
using namespace std;
int main(){
    int y,m;cin >> y >> m;
    bool b = (y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0);
    int ans = 30;
    if (m == 2) ans = b ? 29 : 28;
    if ( m == 1 || m == 3 || m == 7 || m == 8 || m == 10 || m == 12 ) ans = 31;
    cout << ans;
    return 0;
}