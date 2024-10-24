#include <bits/stdc++.h>
using namespace std;
void slove(){
    int a, b;
    cin >> a >> b;
    int diff = b - a;
    int ans;
    if(diff == 0){
        ans = 0;
    }
    if(diff > 0){
        if(diff % 2 == 1){
            ans = 1;
        }else {
            ans = 2;
        }
    }
    if(diff < 0){
        if(diff % 2 == 0){
            ans = 1;
        }else {
            ans = 2;
        }
    }
    cout << ans << '\n';
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