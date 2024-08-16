#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[3];
    int b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    char ans;
    ans = a[0] > b[0] ? 'A' : 'B';
    if (a[0] == b[0]) {
        ans = a[1] > b[1] ? 'A' : 'B';
    }
    if(a[0] == b[0] && a[1] == b[1]){
        ans = a[2] < b[2] ? 'A' : 'B';
    }
    cout << ans;
    return 0;
}