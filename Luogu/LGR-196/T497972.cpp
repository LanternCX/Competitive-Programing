#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int y, m;
    cin >> y >> m;
    cout << ((y - 2016) * 12 + (m - 8 + 1));

    return 0;
}