#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int type, a, b ,c, d;
    cin >> type >> a >> b >> c >> d;
    int ans = 0;
    if(type == 0){
        ans = a + b;
    }else {
        ans = max(a - c, 0) + max(b - d, 0);
    }
    cout << ans;
    return 0;
}